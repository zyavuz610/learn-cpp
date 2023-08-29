/*
  Student Number: 390922
  Full Name: İsmail Hakkı DERELİ
  Phone Number: +90 530 775 90 80
  E-Mail Adress: 390922@ogr.ktu.edu.tr
  KTU OOP Midterm Assignment
  Tested on Ubuntu 18.04.03 with gcc 7.4.0 and c++14 standard
*/

// Inclusion of necessary libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <type_traits>
#include <utility>

// Some preprocessor definitions to shorten code
#define FILE_EXISTS(X) \
  X + " already exists. Overwrite the file? (Y/y for yes): "
#define BTI(X) \
  reinterpret_cast<char*>(&X)
#define ITB(X) \
  reinterpret_cast<const char*>(&X)
#define TDA(T, N, R, C) \
  T** N = new T*[R]; \
  for(int i = 0; i < R; i++) N[i] = new T[C];
#define TF(X) template<X>
#define RP(X) typename remove_pointer<X>::type
#define ONLY_ARITHMETIC(X) \
  typename enable_if<is_arithmetic<X>::value>::type* = nullptr
#define SOL(X, Y) X < Y ? X : X - 1
#define INVALID_DIMENSION "Each dimension must be minimum 1."
#define INVALID_MANIPULATOR "Unrecognized manipulator parameter given."
#define INVALID_FILE_NAME "File name invalid."
#define FILE_DOES_NOT_EXIST "File does not exist."
#define INVALID_FILE_EXTENSION "File extension invalid."
#define INVALID_IDENTITY_MATRIX "Identity matrix must be square."
#define DIMENSIONS_MISMATCH "Given matrices can not be processed."
#define INVALID_INDEX "Given index not found in matrix."
#define INVALID_IMAGE "Given image can not be processed."
#define BINARY_PRINT_COLOR "Color must be gray to print .bin file."
#define BINARY_PRINT_SIZE "Maximum dimesions for .bin file is 255x255."
#define INVALID_BMP "Given .bmp file is not correct or not supported."

// Namespace definition to shorten code
using namespace std;

// Checks file is in good condition and ready to process
inline bool isFileExists(const string& name){
    ifstream f(name.c_str());
    return f.good();
}

// Calculate power for arithmetic base and integer exponent
template<class T, ONLY_ARITHMETIC(T)> auto pow(T base, int exponent){
  double result = 1.0;
  for(int i = 0; i < exponent; i++)
    result *= base;
  return result;
}

// Create cofactor matrix based on given parameters
auto getCofactor(int size, auto** m, auto** c, int row, int column){
  for(int i = 0; i < size; i++){
    if(i == row) continue;
    for(int j = 0; j < size; j++){
      if(j == column) continue;
      c[SOL(i, row)][SOL(j, column)] = m[i][j];
    }
  }
  return c;
}

// Calculate determinant of two dimensinal array
auto calcDet(int size, auto** m){
  if(size == 1)
    return m[0][0];
  if(size == 2)
    return m[0][0] * m[1][1] - m[0][1] * m[1][0];
  else{
    RP(RP(decltype(m))) d = 0;
    for(int i = 0; i < size; i++){
      decltype(m) c = new RP(decltype(m))[size - 1];
      for(int i = 0; i < size - 1; i++)
        c[i] = new RP(RP(decltype(m)))[size - 1];
      getCofactor(size, m, c, 0, i);
      d += pow(-1, i) * m[0][i] * calcDet(size - 1, c);
    }
    return d;
  }
}

// Template Matrix class definition
template<class T> class Matrix{
  private:
    void checkDimensions(int, int);
    void initializeMatrix();
    void fillMatrix(T);
    void deleteMatrix();
  protected:
    void randomMatrix();
    uint32_t column, row;
    T** matrix;
  public:
    Matrix();
    Matrix(T&);
    Matrix(int, int, T);
    Matrix(int, int, char);
    virtual ~Matrix();
    void resize(int, int);
    void print();
    void print(string);
    void operator=(const Matrix<T>&);
    Matrix<T> operator+(const Matrix<T>&);
    Matrix<T> operator-(const Matrix<T>&);
    Matrix<T> operator*(const Matrix<T>&);
    Matrix<T> operator+(int);
    Matrix<T> operator-(int);
    Matrix<T> operator*(int);
    Matrix<T> operator/(int);
    Matrix<T> operator%(int);
    Matrix<T> operator^(int);
    int getRowCount();
    int getColumnCount();
    void getMatrix(T**);
    void setMatrix(T**);
    Matrix<T> transpose();
    Matrix<T> multiply(const Matrix<T>&);
    T determinant();
    Matrix<double> inverse();
};

// Validates dimensions to prevent further errors
template<class T> void Matrix<T>::checkDimensions(int row, int column){
  if(row < 1 || column < 1)
    throw invalid_argument(INVALID_DIMENSION);
}

// Creates two dimensional array based on template parameter
template<class T> void Matrix<T>::initializeMatrix(){
  this->matrix = new T*[this->row];
  for(int i = 0; i < this->row; i++)
    this->matrix[i] = new T[this->column];
}

// Fills matrix with random values if template parameter is integer
template<> void Matrix<int>::randomMatrix(){
  srand(time(NULL));
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      this->matrix[i][j] = rand() % 256;
}

// Fills matrix with given value
template<class T> void Matrix<T>::fillMatrix(T fill){
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      this->matrix[i][j] = fill;
}

// Deletes two dimensional array
template<class T> void Matrix<T>::deleteMatrix(){
  for(int i = 0; i < this->row; i++)
    delete [] this->matrix[i];
  delete [] this->matrix;
}

// No parameter constructor
template<class T> Matrix<T>::Matrix(){
  this->row = this->column = 10;
  this->initializeMatrix();
  this->fillMatrix(*(new T));
}

// Copy constructor
template<class T> Matrix<T>::Matrix(T& it){
  this->row = it.row;
  this->column = it.column;
  this->initializeMatrix();
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      this->matrix[i][j] = it.matrix[i][j];
}

// Constructor with initializer parameters
template<class T> Matrix<T>::Matrix(int row, int column, T fill){
  this->checkDimensions(row, column);
  this->row = row;
  this->column = column;
  this->initializeMatrix();
  this->fillMatrix(fill);
}

// Constructor with special modifiers
template<class T> Matrix<T>::Matrix(int row, int column, char type){
  this->checkDimensions(row, column);
  this->row = row;
  this->column = column;
  this->initializeMatrix();
  if(type == 'e'){
    if(this->row != this->column){
      this->deleteMatrix();
      throw invalid_argument(INVALID_IDENTITY_MATRIX);
    }
    this->fillMatrix(0);
    for(int i = 0; i < this->row; i++)
      this->matrix[i][i] = 1;
  }
  else if(type == 'r')
    this->randomMatrix();
  else
    throw invalid_argument(INVALID_MANIPULATOR);
}

// Destructor
template<class T> Matrix<T>::~Matrix(){
  this->deleteMatrix();
}

// Resize dynamic array based on given parameters
template<class T> void Matrix<T>::resize(int row, int column){
  this->checkDimensions(row, column);
  if(this->row > row)
    for(int i = this->row; i > row; i--)
      delete [] this->matrix[i - 1];
  this->matrix = (T**)realloc(this->matrix, row * sizeof(T*));
  for(int i = this->row; i < row; i++)
    this->matrix[i] = new T[column];
  this->row = row;
  for(int i = 0; i < this->row; i++){
    this->matrix[i] = (T*)realloc(this->matrix[i], column * sizeof(T));
    for(int j = this->column; j < column; j++)
      this->matrix[i][j] = *(new T);
  }
  this->column = column;
}

// Print matrix to terminal
template<class T> void Matrix<T>::print(){
  for(int i = 0; i < this->row; i++){
    for(int j = 0; j < this->column; j++)
      cout << setw(4) << this->matrix[i][j];
    cout << endl;
  }
}

// Print matrix to given file
template<class T> void Matrix<T>::print(string file_name){
  if(file_name.empty())
    throw invalid_argument(INVALID_FILE_NAME);
  if(isFileExists(file_name)){
    cout << FILE_EXISTS(file_name);
    uint8_t selection;
    cin >> selection;
    if(selection != 'Y' && selection != 'y')
      return;
  }
  ofstream file(file_name);
  for(int i = 0; i < this->row; i++){
    for(int j = 0; j < this->column; j++)
      file << setw(4) << this->matrix[i][j];
    file << endl;
  }
  file.close();
}

// Assigment operator overloading for deep copy
template<class T> void Matrix<T>::operator=(const Matrix<T>& it){
  this->deleteMatrix();
  this->row = it.row;
  this->column = it.column;
  this->initializeMatrix();
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      this->matrix[i][j] = it.matrix[i][j];
}

// Addition operator overloading for matris addition
template<class T> Matrix<T> Matrix<T>::operator+(const Matrix<T>& it){
  if(this->row != it.row || this->column != it.column)
    throw invalid_argument(DIMENSIONS_MISMATCH);
  Matrix<T> matrix(this->row, this->column, 0);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      matrix.matrix[i][j] = this->matrix[i][j] + it.matrix[i][j];
  return matrix;
}

// Subtraction operator overloading for matris subtraction
template<class T> Matrix<T> Matrix<T>::operator-(const Matrix<T>& it){
  if(this->row != it.row || this->column != it.column)
    throw invalid_argument(DIMENSIONS_MISMATCH);
  Matrix<T> matrix(this->row, this->column, 0);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      matrix.matrix[i][j] = this->matrix[i][j] - it.matrix[i][j];
  return matrix;
}

// Multiplication operator overloading for matris multiplication
template<class T> Matrix<T> Matrix<T>::operator*(const Matrix<T>& it){
  if(this->column != it.row)
    throw invalid_argument(DIMENSIONS_MISMATCH);
  Matrix<T> matrix(this->row, it.column, 0);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < it.column; j++)
      for(int k = 0; k < this->column; k++)
        matrix.matrix[i][j] += this->matrix[i][k] * it.matrix[k][j];
  return matrix;
}

// Addition operator overloading for scalar addition
template<class T> Matrix<T> Matrix<T>::operator+(int number){
  Matrix<T> matrix(this->row, this->column, 0);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      matrix.matrix[i][j] = this->matrix[i][j] + number;
  return matrix;
}

// Subtraction operator overloading for scalar subtraction
template<class T> Matrix<T> Matrix<T>::operator-(int number){
  Matrix<T> matrix(this->row, this->column, 0);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      matrix.matrix[i][j] = this->matrix[i][j] - number;
  return matrix;
}

// Multiplication operator overloading for scalar multiplication
template<class T> Matrix<T> Matrix<T>::operator*(int number){
  Matrix<T> matrix(this->row, this->column, 0);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      matrix.matrix[i][j] = this->matrix[i][j] * number;
  return matrix;
}

// Division operator overloading for scalar division
template<class T> Matrix<T> Matrix<T>::operator/(int number){
  Matrix<T> matrix(this->row, this->column, 0);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      matrix.matrix[i][j] = this->matrix[i][j] / number;
  return matrix;
}

// Modulo operator overloading for scalar modulo
template<class T> Matrix<T> Matrix<T>::operator%(int number){
  Matrix<T> matrix(this->row, this->column, 0);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      matrix.matrix[i][j] = this->matrix[i][j] % number;
  return matrix;
}

// Power operator overloading for scalar power
template<class T> Matrix<T> Matrix<T>::operator^(int number){
  Matrix<T> matrix(this->row, this->column, 0);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      matrix.matrix[i][j] = pow(this->matrix[i][j], number);
  return matrix;
}

// Return row count
template<class T> int Matrix<T>::getRowCount(){
  return this->row;
}

// Return column count
template<class T> int Matrix<T>::getColumnCount(){
  return this->column;
}

// Copy values from matrix to given dynamic array
template<class T> void Matrix<T>::getMatrix(T** matrix){
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->row; j++)
      matrix[i][j] = this->matrix[i][j];
}

// Copy values from given dynamic array to matrix
template<class T> void Matrix<T>::setMatrix(T** matrix){
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->row; j++)
      this->matrix[i][j] = matrix[i][j];
}

// Calculate transpose of matrix
template<class T> Matrix<T> Matrix<T>::transpose(){
  Matrix<T> matrix(this->column, this->row, *(new T));
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      matrix.matrix[j][i] = this->matrix[i][j];
  return matrix;
}

// Element level multiplication of matrices
template<class T> Matrix<T> Matrix<T>::multiply(const Matrix<T>& it){
  if(this->row != it.row || this->column != it.column)
    throw invalid_argument(DIMENSIONS_MISMATCH);
  Matrix<T> matrix(this->row, this->column, 0);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++)
      matrix.matrix[i][j] = this->matrix[i][j] * it.matrix[i][j];
  return matrix;
}

// Calculate determinant of matrix
template<class T> T Matrix<T>::determinant(){
  if(this->row != this->column)
    throw invalid_argument(DIMENSIONS_MISMATCH);
  return calcDet(this->row, this->matrix);
}

// Calculate inverse of matrix
template<class T> Matrix<double> Matrix<T>::inverse(){
  double determinant = static_cast<double>(this->determinant());
  if(!determinant)
    throw invalid_argument(DIMENSIONS_MISMATCH);
  TDA(T, m, this->row, this->column)
  this->transpose().getMatrix(m);
  int size = this->row - 1;
  TDA(T, c, size, size)
  TDA(double, r, this->row, this->column)
  for(int i = 0; i < this->row; i++){
    for(int j = 0; j < this->column; j++){
      getCofactor(this->row, m, c, i, j);
      auto det = calcDet(size, c);
      r[i][j] = static_cast<double>(det) / determinant;
    }
  }
  Matrix<double> inverse(this->row, this->column, 0.0);
  inverse.setMatrix(r);
  return inverse;
}

// RGB struct definition
struct RGB{
  uint8_t red;
  uint8_t green;
  uint8_t blue;
  RGB();
};

// Default constructor to set pixel values to zero
RGB::RGB(){
  this->red = this->green = this->blue = 0;
}

// Image class definition
class Image : private Matrix<RGB>{
  private:
    uint16_t bit;
  public:
    Image();
    Image(int, int);
    Image(string, string);
    Image(Image&);
    ~Image();
    void operator=(Image&);
    void readImage(string, string);
    void writeImage(string, string);
    void toGray();
    void toBinary(int);
    void erosion();
    void dilation();
    void opening();
    void closing();
};

// No parameter constructor
Image::Image() : Matrix(255, 255, RGB()){
  this->bit = 1;
};

// Constructor with initializer parameters
Image::Image(int h, int w) : Matrix(h, w, RGB()){
  this->bit = 1;
};

// Constructor with file reading
Image::Image(string n, string f) : Matrix(1, 1, RGB()){
  this->bit = 1;
  this->readImage(n, f);
}

// Copy constructor
Image::Image(Image& it) : Matrix(1, 1, RGB()){
  this->bit = it.bit;
  Matrix::operator=(it);
}

// Destructor
Image::~Image(){}

// Read image from file
void Image::readImage(string name, string type){
  if(name.empty())
    throw invalid_argument(INVALID_FILE_NAME);
  if(type.empty())
    throw invalid_argument(INVALID_FILE_EXTENSION);
  string file_name = name + "." + type;
  if(!isFileExists(file_name))
    throw invalid_argument(FILE_DOES_NOT_EXIST);
  ifstream file(file_name, fstream::binary);
  if(type == "bmp"){
    uint16_t signature;
    file.read(BTI(signature), 2);
    if(signature != 19778)
      throw invalid_argument(INVALID_BMP);
    uint32_t file_size;
    file.read(BTI(file_size), 4);
    uint32_t reserved;
    file.read(BTI(reserved), 4);
    if(reserved != 0)
      throw invalid_argument(INVALID_BMP);
    uint32_t data_offset;
    file.read(BTI(data_offset), 4);
    uint32_t header;
    file.read(BTI(header), 4);
    if(header != 40)
      throw invalid_argument(INVALID_BMP);
    uint32_t width;
    file.read(BTI(width), 4);
    uint32_t height;
    file.read(BTI(height), 4);
    uint16_t planes;
    file.read(BTI(planes), 2);
    if(planes != 1)
      throw invalid_argument(INVALID_BMP);
    uint16_t bpp;
    file.read(BTI(bpp), 2);
    if(bpp != 1 && bpp != 8 && bpp != 24)
      throw invalid_argument(INVALID_BMP);
    if(bpp == 24)
      if(file_size != 14 + header + 3 * width * height)
        throw invalid_argument(INVALID_BMP);
    else
      if(file_size != 14 + header + 4 * pow(2, bpp) + width * height)
        throw invalid_argument(INVALID_BMP);
    uint32_t compression;
    file.read(BTI(compression), 4);
    if(compression != 0)
      throw invalid_argument(INVALID_BMP);
    uint32_t image_size;
    file.read(BTI(image_size), 4);
    if(image_size != width * height)
      throw invalid_argument(INVALID_BMP);
    uint32_t x_pixels_per_m;
    file.read(BTI(x_pixels_per_m), 4);
    uint32_t y_pixels_per_m;
    file.read(BTI(y_pixels_per_m), 4);
    uint32_t colors_used;
    file.read(BTI(colors_used), 4);
    if(colors_used != pow(2, bpp))
      throw invalid_argument(INVALID_BMP);
    uint32_t important_colors;
    file.read(BTI(important_colors), 4);
    if(important_colors != 0)
      throw invalid_argument(INVALID_BMP);
    this->resize(height, width);
    if(bpp == 24){
      for(int i = this->row - 1; i >= 0; i--){
        for(int j = 0; j < this->column; j++){
          file.read(BTI(this->matrix[i][j].blue), 1);
          file.read(BTI(this->matrix[i][j].green), 1);
          file.read(BTI(this->matrix[i][j].red), 1);
        }
      }
    }else{
      char* buffer = new char[1024];
      file.read(buffer, 4 * pow(2, bpp));
      for(int i = this->row - 1; i >= 0; i--){
        for(int j = 0; j < this->column; j++){
          uint8_t pixel;
          file.read(BTI(pixel), 1);
          this->matrix[i][j].red = (unsigned int)(unsigned char)buffer[4 * pixel];
          this->matrix[i][j].green = this->matrix[i][j].blue = 0;
        }
      }
    }
    this->bit = bpp;
  }
  else if(type == "bin"){
    uint8_t height;
    file.read(BTI(height), 1);
    uint8_t width;
    file.read(BTI(width), 1);
    this->resize(height, width);
    for(int i = 0; i < this->row; i++)
      for(int j = 0; j < this->column; j++)
        file.read(BTI(this->matrix[i][j].red), 1);
    this->bit = 8;
  }
  else
    throw invalid_argument(INVALID_FILE_EXTENSION);
}

// Write image to file
void Image::writeImage(string name, string type){
  if(name.empty())
    throw invalid_argument(INVALID_FILE_NAME);
  if(type.empty())
    throw invalid_argument(INVALID_FILE_EXTENSION);
  string file_name = name + "." + type;
  if(isFileExists(file_name)){
    cout << FILE_EXISTS(file_name);
    uint8_t selection;
    cin >> selection;
    if(selection != 'Y' && selection != 'y')
      return;
  }
  ofstream file(file_name, fstream::binary);
  if(type == "bmp"){
    char* buffer = new char[4];
    buffer[0] = 'B';
    buffer[1] = 'M';
    file.write(buffer, 2);
    delete [] buffer;
    uint32_t image_size = this->row * this->column;
    uint32_t file_size = 54;
    uint32_t colors_used = 0;
    if(this->bit < 24)
      colors_used = pow(2, this->bit);
    int colors_table_size = 4 * colors_used;
    uint8_t padding = 0;
    if(this->bit == 24){
      if(this->column % 4)
        padding = 4 - this->column % 4;
      file_size += 3 * this->row * (this->column + padding);
    }else if(this->bit == 8)
      file_size += colors_table_size + image_size;
    else
      file_size += colors_table_size + image_size;
    file.write(ITB(file_size), 4);
    uint32_t reserved = 0;
    file.write(ITB(reserved), 4);
    uint32_t offset = 54 + colors_table_size;
    file.write(ITB(offset), 4);
    uint32_t header_size = 40;
    file.write(ITB(header_size), 4);
    file.write(ITB(this->column), 4);
    file.write(ITB(this->row), 4);
    uint16_t planes = 1;
    file.write(ITB(planes), 2);
    file.write(ITB(this->bit), 2);
    uint32_t compression = 0;
    file.write(ITB(compression), 4);
    file.write(ITB(image_size), 4);
    uint32_t x_pixels_per_m = 0;
    file.write(ITB(x_pixels_per_m), 4);
    uint32_t y_pixels_per_m = 0;
    file.write(ITB(y_pixels_per_m), 4);
    file.write(ITB(colors_used), 4);
    uint32_t import_colors = 0;
    file.write(ITB(import_colors), 4);
    uint8_t unused = 0;
    if(colors_used){
      uint8_t color = 0;
      while(color < colors_used){
        file.write(ITB(color), 1);
        file.write(ITB(color), 1);
        file.write(ITB(color), 1);
        file.write(ITB(unused), 1);
        if(color == colors_used - 1)
          break;
        color++;
      }
      for(int i = this->row - 1; i >= 0; i--)
        for(int j = 0; j < this->column; j++)
          file.write(ITB(this->matrix[i][j].red), 1);
    }else{
      for(int i = this->row - 1; i >= 0; i--){
        for(int j = 0; j < this->column; j++){
          file.write(ITB(this->matrix[i][j].blue), 1);
          file.write(ITB(this->matrix[i][j].green), 1);
          file.write(ITB(this->matrix[i][j].red), 1);
        }
        for(int j = 0; j < padding; j++)
          file.write(ITB(unused), 1);
      }
    }
  }
  else if(type == "bin"){
    if(this->bit > 8)
      throw invalid_argument(BINARY_PRINT_COLOR);
    if(this->row > 255 || this->column > 255)
      throw invalid_argument(BINARY_PRINT_SIZE);
    file.write(ITB(this->row), 1);
    file.write(ITB(this->column), 1);
    for(int i = 0; i < this->row; i++)
      for(int j = 0; j < this->column; j++)
        file.write(ITB(this->matrix[i][j].red), 1);
  }
  else
    throw invalid_argument(INVALID_FILE_EXTENSION);
}

// Convert colored image to gray
void Image::toGray(){
  if(this->bit <= 8)
    throw invalid_argument(INVALID_IMAGE);
  for(int i = 0; i < this->row; i++){
    for(int j = 0; j < this->column; j++){
      int linear_intensity = 0.2126 * this->matrix[i][j].red;
      linear_intensity += 0.7152 * this->matrix[i][j].green;
      linear_intensity += 0.0722 * this->matrix[i][j].blue;
      this->matrix[i][j].red = (char)linear_intensity;
      this->matrix[i][j].green = this->matrix[i][j].blue = 0;
    }
  }
  this->bit = 8;
}

// Convert gray image to binary based on given threshold
void Image::toBinary(int threshold){
  if(this->bit == 1 || this->bit == 24)
    throw invalid_argument(INVALID_IMAGE);
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->column; j++){
      this->matrix[i][j].red = this->matrix[i][j].red > threshold;
    }
  this->bit = 1;
}

// Apply erosion effect to binary image
void Image::erosion(){
  if(this->bit != 1)
    throw invalid_argument(INVALID_IMAGE);
  TDA(bool, temp, this->row, this->column);
  for(int i = 0; i < this->column; i++)
    temp[0][i] = temp[this->row - 1][i] = 0;
  for(int i = 0; i < this->row; i++)
    temp[i][0] = temp[i][this->column - 1] = 0;
  for(int i = 1; i < this->row - 1; i++){
    for(int j = 1; j < this->column - 1; j++){
      temp[i][j] = this->matrix[i][j].red;
      if(temp[i][j]){
        for(int k = i - 1; k <= i + 1; k++){
          for(int l = j - 1; l <= j + 1; l++){
            if(!this->matrix[k][l].red){
              temp[i][j] = matrix[k][l].red;
              k = i + 1;
              l = j + 1;
            }
          }
        }
      }
    }
  }
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->row; j++)
      this->matrix[i][j].red = temp[i][j];
}

// Apply dilation effect to binary image
void Image::dilation(){
  if(this->bit != 1)
    throw invalid_argument(INVALID_IMAGE);
  TDA(bool, temp, this->row, this->column);
  for(int i = 0; i < this->row; i++){
    for(int j = 0; j < this->column; j++){
      temp[i][j] = this->matrix[i][j].red;
      if(!temp[i][j]){
        for(int k = i - 1; k <= i + 1; k++){
          if(k < 0)
            continue;
          if(k > this->row - 1)
            break;
          for(int l = j - 1; l <= j + 1; l++){
            if(l < 0)
              continue;
            if(l > this->column - 1)
              break;
            if(this->matrix[k][l].red){
              temp[i][j] = this->matrix[k][l].red;
              k = i + 1;
              l = j + 1;
            }
          }
        }
      }
    }
  }
  for(int i = 0; i < this->row; i++)
    for(int j = 0; j < this->row; j++)
      this->matrix[i][j].red = temp[i][j];
}

// Apply opening effect to binary image
void Image::opening(){
  this->erosion();
  this->dilation();
}

// Apply closing effect to binary image
void Image::closing(){
  this->dilation();
  this->erosion();
}

// Template Table class definition
template<class T> class Table : private Matrix<T>{
  private:
    void initializeNames();
    string* rows;
    string* columns;
  public:
    Table();
    Table(int, int, T);
    Table(int, int, char);
    Table(Table&);
    ~Table();
    void operator=(Table&);
    T itemAt(int, int);
    T itemAt(string, string);
    T itemAt(string);
    void setRowNames(string*, int);
    void setColumnNames(string*, int);
    void print();
};

// Create default row and column names
template<class T> void Table<T>::initializeNames(){
  this->rows = new string[this->row];
  this->columns = new string[this->column];
  for(int i = 0; i < this->row; i++)
    this->rows[i] = to_string(i);
  for(char i = 0; i < this->column; i++)
    this->columns[i] = static_cast<char>('A' + i);
}

// No parameter constructor
template<class T> Table<T>::Table(){
  this->initializeNames();
}

// Constructor with initializer parameters
template<class T> Table<T>::Table(int row, int column, T fill)
  : Matrix<T>(row, column, fill){
  this->initializeNames();
}

// Constructor with special modifiers
template<class T> Table<T>::Table(int row, int column, char type)
  : Matrix<T>(row, column, *(new T)){
  this->initializeNames();
  if(type == 'r')
    this->randomMatrix();
}

// Copy Constructors
template<class T> Table<T>::Table(Table& it)
  : Matrix<T>(it.row, it.column, *(new T)){
  this->initializeNames();
  for(int i = 0; i < this->row; i++){
    this->rows[i] = it.rows[i];
    for(int j = 0; j < this->column; j++)
      this->matrix[i][j] = it.matrix[i][j];
  }
  for(int i = 0; i < this->column; i++)
    this->columns[i] = it.columns[i];
}

// Destructor
template<class T> Table<T>::~Table(){
  delete [] this->columns;
  delete [] this->rows;
}

// Assignment operator overloading
template<class T> void Table<T>::operator=(Table& it){
  delete [] this->rows;
  delete [] this->columns;
  Matrix<T>::operator=(it);
  this->initializeNames();
  for(int i = 0; i < this->row; i++)
    this->rows[i] = it.rows[i];
  for(int i = 0; i < this->column; i++)
    this->columns[i] = it.columns[i];
}

// Get value at given index
template<class T> T Table<T>::itemAt(int row, int column){
  if(row >= this->row || column >= this->column)
    throw invalid_argument(INVALID_INDEX);
  return this->matrix[row][column];
}

// Get value at given index
template<class T> T Table<T>::itemAt(string row, string column){
  int row_index, column_index;
  row_index = column_index = -1;
  for(int i = 0; i < this->row; i++){
    if(!this->rows[i].compare(row)){
      row_index = i;
      break;
    }
  }
  for(int i = 0; i < this->column; i++){
    if(!this->columns[i].compare(column)){
      column_index = i;
      break;
    }
  }
  if(row_index == -1 || column_index == -1)
    throw invalid_argument(INVALID_INDEX);
  return this->matrix[row_index][column_index];
}

// Get value at given index
template<class T> T Table<T>::itemAt(string index){
  if(index.size() != 2)
    throw invalid_argument("Required index like 'A0'");
  return this->itemAt(string(1, index[1]), string(1, index[0]));
}

// Set row names based on given parameters
template<class T> void Table<T>::setRowNames(string* names, int n){
  for(int i = 0; i < (n < this->row ? n : this->row); i++){
    if(names[i].size() > 8)
      this->rows[i] = names[i].substr(0, 8);
    else
      this->rows[i] = names[i];
  }
}

// Set column names based on given parameters
template<class T> void Table<T>::setColumnNames(string* names, int n){
  for(int i = 0; i < (n < this->column ? n : this->column); i++){
    if(names[i].size() > 4)
      this->columns[i] = names[i].substr(0, 4);
    else
      this->columns[i] = names[i];
  }
}

// Print matrix to terminal screen with row and column names
template<class T> void Table<T>::print(){
  cout << setw(9) << "" << left;
  for(int i = 0; i < this->column; i++)
    cout << setw(5) << this->columns[i];
  for(int i = 0; i < this->row; i++){
    cout << endl << setw(9) << this->rows[i];
    for(int j = 0; j < this->column; j++)
      cout << setw(5) << this->matrix[i][j];
  }
  cout << endl;
}

int main(){
  Table<int> *m1 = new Table<int>(3, 3, 'r');
  m1->print();
  cout << "-------" << endl;
  Table<int> m2 = *m1;
  m2.print();
  cout << "-------" << endl;
  Table<int> *m3 = new Table<int>(2, 5, 'r');
  m3->print();
  cout << "-------" << endl;
  *m3 = *m1;
  m3->print();
  return 0;
}
