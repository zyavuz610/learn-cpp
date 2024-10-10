/* **************************************************************************************************
*Written by :  Nurullah Demirci
*Department :  Computer Engineering <--> 2. Education
*Number     :  244037
*GSM        :  +90 531 356 0256
*EMail		:  nurullahdemirci061@gmail.com
************************************************************************************************** */
/* **************************************************************************************************
*Base Class		:  Class Matrix {};
*Derived Class	:  Class Image : Public Class Matrix{};
*Derived Class  :  Class Table : Public Class Matrix{};
*template <class Type1> Used for Matrix Class.
*template <class Type2> Used for Image Class.
*template <class Type3> Used for Table Class.
*Matrix Class'ında istenen (char, int, double), random, birim matris değerli matrisler oluşturulabilir.
*Matris objeleri arasında overloading yapılabilir.
*Overloading in amacı main içinde daha sade ve anlaşılır kod yazabilmektir.
*Matrisin determinantı, tersi, transpozu, eleman düzeyinde çarpma, matris dört işlemi,
matris scalar işlemleri yapılabilir. Console çıktı alınabilir.
*Image Sınıfı ile .bin ve .bmp formatlı dosyalar okunup tekrar yazılabilir. Görüntü gray level ve
binary level yapılabilir.
*Image Sınıfı İle Görüntü Üzerinde Morfolojik İşlemler Yapılıp Tekrar dosyaya yazılabilir.
*Table Sınıfı İle Matrisimize Özel Satır Sutunları Tanımlanabilir.
Ve İstenen satır ve sütündaki Değer Geri Döndürülebilir.
************************************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <math.h>
using namespace std;

/* ********************* Matrix.h File ********************* */
template <class Type1>
class Matrix {
public:
	/* ** Constructor Method With Parameters and Without Parameters ** */
	Matrix(int _row = 10, int _col = 10, Type1 _val = 0);

	Type1 getMtrx(int, int);

	void setMtrx(int, int, Type1);

	Type1 getArry(int);

	void setArry(int, Type1);

	/* ** row Getter Method. Tested ** */
	int getRow();

	/* ** col Getter Method. Tested ** */
	int getCol();

	/* ** row-col Setter Method. Tested ** */
	void setRowCol(int r, int c);

	/* ** Matrix Copy Helper Method ** */
	void copyMatrix(unsigned int _row, unsigned int _col);

	/* ** Resize Of Matrix Method** */
	void resize(int _row, int _col);

	/* ** '=' Operator Overloading Method With Object For Matrix Operations ** */
	//Matrix<Type1> operator=(const Matrix<Type1>& m);

	/* ** '+' Operator Overloading Method With Object For Matrix Operations ** */
	Matrix<Type1> operator+(const Matrix<Type1>& m);

	/* ** '-' Operator Overloading Method With Object For Matrix Operations ** */
	Matrix operator-(const Matrix& m);

	/* ** '*' Operator Overloading Method With Object For Matrix Operations ** */
	Matrix operator*(const Matrix& m);

	/* ** '+' Operator Overloading Method With Int Value For Scalar Operations ** */
	Matrix operator+(const Type1 m);

	/* ** '-' Operator Overloading Method With Int Value For Scalar Operations ** */
	Matrix operator-(const Type1 m);

	/* ** '*' Operator Overloading Method With Int Value For Scalar Operations ** */
	Matrix operator*(const Type1 m);

	/* ** '/' Operator Overloading Method With Int Value For Scalar Operations ** */
	Matrix operator/(const Type1 m);

	/* ** '%' Operator Overloading Method With Int Value For Scalar Operations ** */
	Matrix operator%(const Type1 m);

	/* ** '^' Operator Overloading Method With Int Value For Scalar Operations ** */
	Matrix operator^(const Type1 m);

	/* ** Take Matrix Transpose Method ** */
	void T();

	/* ** Matrix Elementwise Multiply Method ** */
	void emul(const Matrix& obj);

	/* ** Inversion Of Matrix Method With Gauss Jordan Rule ** */
	void inv();

	/* ** Determinant Of Matrix Method With Gauss Jordan Rule ** */
	Type1 det();

	/* ** Matrix Print Function Without Parameters ** */
	void print();

	/* ** Matrix Print File Method With File Parameter ** */
	void print(string _file);

	/* ** Matrix Print File Clear Inside Helper Method With File Parameter ** */
	void clear(string _file);

	/* ** Matrix Print Determinant Helper Method ** */
	void print(Type1 det);

	/* ** Destructor Method ** */
	~Matrix();

protected:
	void Create() {
		Mtrx = new Type1 *[row];
		Arry = new Type1[row];
		for (unsigned int i = 0; i < row; i++) {
			Mtrx[i] = new Type1[col];
			Arry[i] = (Type1)0;
		}
		for (unsigned int i = 0; i < row; i++) {
			for (unsigned int j = 0; j < col; j++) {
				Mtrx[i][j] = val;
			}
		}
	}
	Type1 **Mtrx, **cpyMtrx, *Arry;
	unsigned int row, col;
	int fill = 40; // Ekrana Yazmada İşlemlerinde Kullanıldı.
	Type1 val, determinant;
	string file;
private:
};
/* ********************* Matrix.cpp File ********************* */

/* ** Constructor Method With Parameters and Without Parameters. Tested ** */
template <class Type1>
Matrix<Type1>::Matrix(int _row, int _col, Type1 _val) {
	this->row = _row;
	this->col = _col;
	this->val = _val;
	this->Create();
	if (_val == 'e' && this->row == this->col) {
		for (unsigned int i = 0; i < this->row; i++) {
			for (unsigned int j = 0; j < this->col; j++) {
				if (i == j) Mtrx[i][j] = (Type1)1;
				else Mtrx[i][j] = (Type1)0;
			}
		}
	}
	if (_val == 'e' && this->row != col) {
		for (unsigned int i = 0; i < this->row; i++) {
			for (unsigned int j = 0; j < this->col; j++) {
				Mtrx[i][j] = (Type1)0;
			}
		}
		cout << "Birim Matris Sadece Kare Matrisler Icin Gecerlidir!\n";
		cout << right << setfill('-') << setw(this->fill) << "\n";
	}
	if (_val == 'r') {
		srand(time_t(NULL));
		for (unsigned int i = 0; i < row; i++) {
			for (unsigned int j = 0; j < col; j++) {
				Mtrx[i][j] = rand() % 255 + 0;
			}
		}
	}
}

/* ** Matrix Getter Method. Tested ** */
template <class Type1>
Type1 Matrix<Type1>::getMtrx(int r, int c) {
	return this->Mtrx[r][c];
}
/* ** Matrix Setter Method. Tested ** */
template <class Type1>
void Matrix<Type1>::setMtrx(int r, int c, Type1 v) {
	this->Mtrx[r][c] = v;
}
/* ** Array Getter Method. Tested ** */
template <class Type1>
Type1 Matrix<Type1>::getArry(int r) {
	return this->Arry[r];
}
/* ** Array Setter Method. Tested ** */
template <class Type1>
void Matrix<Type1>::setArry(int r, Type1 v) {
	this->Arry[r] = v;
}
/* ** row Getter Method. Tested ** */
template <class Type1>
int Matrix<Type1>::getRow() {
	return this->row;
}
/* ** col Getter Method. Tested ** */
template <class Type1>
int Matrix<Type1>::getCol() {
	return this->col;
}
/* ** row-col Setter Method. Tested ** */
template <class Type1>
void Matrix<Type1>::setRowCol(int r, int c) {
	this->row = r;
	this->col = c;
}

/* ** Matrix Copy Helper Method. Tested ** */
template <class Type1>
void Matrix<Type1>::copyMatrix(unsigned int _row, unsigned int _col) {
	int r, c;
	if (this->row > _row)    r = this->row;
	else              r = _row;
	if (this->col > _col)    c = this->col;
	else              c = _col;
	cpyMtrx = new Type1 *[r];
	for (int i = 0; i < r; i++) {
		cpyMtrx[i] = new Type1[c];
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cpyMtrx[i][j] = (Type1)0;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cpyMtrx[i][j] = Mtrx[i][j];
		}
	}
}

/* ** Resize Of Matrix Method. Tested ** */
template <class Type1>
void Matrix<Type1>::resize(int _row, int _col) {
	this->copyMatrix(_row, _col);
	this->row = _row;
	this->col = _col;
	this->Create();
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Mtrx[i][j] = cpyMtrx[i][j];
		}
	}
	for (int i = 0; i < row; i++)
		delete[] cpyMtrx[i];
	delete[] cpyMtrx;
}

/* ** '=' Operator Overloading Method With Object For Matrix Operations ** */
/*template <class Type1>
Matrix<Type1> Matrix<Type1>::operator=(const Matrix& m) {
	Matrix<Type1> temp(this->row, this->col, (Type1)0);
	int i, j;
	this->row = m.row;
	this->col = m.col;
	this->Create();
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			this->Mtrx[i][j] = m.Mtrx[i][j];
			temp.Mtrx[i][j] = this->Mtrx[i][j];
		}
	}
	return temp;
}*/

/* ** '+' Operator Overloading Method With Object For Matrix Operations ** */
template <class Type1>
Matrix<Type1> Matrix<Type1>::operator+(const Matrix<Type1>& m) {
	Matrix<Type1> temp(this->row, this->col, (Type1)0);
	unsigned int i, j;
	if (this->row == m.row && this->col == m.col)
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j] + m.Mtrx[i][j];
			}
		}
	else {
		cout << "Matrix'ler Denk Degil!\n";
		cout << right << setfill('-') << setw(this->fill) << "\n";
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j];
			}
		}
	}
	return temp;
}

/* ** '-' Operator Overloading Method With Object For Matrix Operations ** */
template <class Type1>
Matrix<Type1> Matrix<Type1>::operator-(const Matrix& m) {
	Matrix<Type1> temp(this->row, this->col, (Type1)0);
	unsigned int i, j;
	if (this->row == m.row && this->col == m.col)
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j] - m.Mtrx[i][j];
			}
		}
	else {
		cout << "Matrix'ler Denk Degil!\n";
		cout << right << setfill('-') << setw(this->fill) << "\n";
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j];
			}
		}
	}
	return temp;
}

/* ** '*' Operator Overloading Method With Object For Matrix Operations ** */
template <class Type1>
Matrix<Type1> Matrix<Type1>::operator*(const Matrix& m) {
	Matrix<Type1> temp(this->row, this->col, (Type1)0);
	unsigned int i, j;
	if (this->row == m.row && this->col == m.col)
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j] * m.Mtrx[i][j];
			}
		}
	else {
		cout << "Matrix'ler Denk Degil!\n";
		cout << right << setfill('-') << setw(this->fill) << "\n";
		for (i = 0; i < this->row; i++) {
			for (j = 0; j < this->col; j++) {
				temp.Mtrx[i][j] = this->Mtrx[i][j];
			}
		}
	}
	return temp;
}

/* ** '+' Operator Overloading Method With Int Value For Scalar Operations ** */
template <class Type1>
Matrix<Type1> Matrix<Type1>::operator+(const Type1 m) {
	Matrix<Type1> temp(this->row, this->col, (Type1)0);
	unsigned int i, j;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->col; j++) {
			temp.Mtrx[i][j] = this->Mtrx[i][j] + m;
		}
	}
	return temp;
}

/* ** '-' Operator Overloading Method With Int Value For Scalar Operations ** */
template <class Type1>
Matrix<Type1> Matrix<Type1>::operator-(const Type1 m) {
	Matrix<Type1> temp(this->row, this->col, (Type1)0);
	unsigned int i, j;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->col; j++) {
			temp.Mtrx[i][j] = this->Mtrx[i][j] - m;
		}
	}
	return temp;
}

/* ** '*' Operator Overloading Method With Int Value For Scalar Operations ** */
template <class Type1>
Matrix<Type1> Matrix<Type1>::operator*(const Type1 m) {
	Matrix<Type1> temp(this->row, this->col, (Type1)0);
	unsigned int i, j;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->col; j++) {
			temp.Mtrx[i][j] = this->Mtrx[i][j] * m;
		}
	}
	return temp;
}

/* ** '/' Operator Overloading Method With Int Value For Scalar Operations ** */
template <class Type1>
Matrix<Type1> Matrix<Type1>::operator/(const Type1 m) {
	Matrix<Type1> temp(this->row, this->col, (Type1)0);
	unsigned int i, j;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->col; j++) {
			temp.Mtrx[i][j] = this->Mtrx[i][j] / m;
		}
	}
	return temp;
}

/* ** '%' Operator Overloading Method With Int Value For Scalar Operations ** */
template <class Type1>
Matrix<Type1> Matrix<Type1>::operator%(const Type1 m) {
	Matrix<Type1> temp(this->row, this->col, (Type1)0);
	unsigned int i, j;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->col; j++) {
			temp.Mtrx[i][j] = (int)this->Mtrx[i][j] % (int)m;
		}
	}
	return temp;
}

/* ** '^' Operator Overloading Method With Int Value For Scalar Operations ** */
template <class Type1>
Matrix<Type1> Matrix<Type1>::operator^(const Type1 m) {
	Matrix<Type1> temp(this->row, this->col, (Type1)0);
	unsigned int i, j;
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->col; j++) {
			temp.Mtrx[i][j] = pow(this->Mtrx[i][j], m);
		}
	}
	return temp;
}

/* ** Take Matrix Transpose Method ** */
template <class Type1>
void Matrix<Type1>::T() {
	unsigned int _row, _col;
	_row = this->col;
	_col = this->row;
	Matrix<Type1> temp(_row, _col, (Type1)0);
	for (unsigned int i = 0; i < _col; i++) {
		for (unsigned int j = 0; j < _row; j++) {
			temp.Mtrx[j][i] = this->Mtrx[i][j];
		}
	}
	this->row = _row;
	this->col = _col;
	this->Create();
	for (unsigned int i = 0; i < this->row; i++) {
		for (unsigned int j = 0; j < this->col; j++) {
			this->Mtrx[i][j] = temp.Mtrx[i][j];
		}
	}
}

/* ** Matrix Elementwise Multiply Method ** */
template <class Type1>
void Matrix<Type1>::emul(const Matrix& obj) {
	Type1 _val, total = (Type1)0;;
	Matrix<Type1> temp(this->row, obj.col, (Type1)0);
	//cout << this->col << endl;
	//cout << obj.row << endl;
	if (this->col == obj.row) {
		for (unsigned int i = 0; i < this->row; i++) {
			for (unsigned int k = 0; k < obj.col; k++) {
				for (unsigned int j = 0; j < obj.row; j++) {
					_val = this->Mtrx[i][j] * obj.Mtrx[j][k];
					total += _val;
				}
				temp.Mtrx[i][k] = total;
				total = (Type1)0;
			}
		}
		this->col = obj.col;
		this->Create();
		for (unsigned int i = 0; i < this->row; i++) {
			for (unsigned int j = 0; j < this->col; j++) {
				this->Mtrx[i][j] = temp.Mtrx[i][j];
			}
		}
	}
	else {
		cout << "1. Matrix'in Sutun ile 2. Matrix'in Satir Degerleri Esit Olmalidir!\n";
		cout << right << setfill('-') << setw(this->fill) << "\n";
	}
}

template <class Type1>
void Matrix<Type1>::inv() {
	Type1 _det = det();
	// Determinant sıfır mı ve Matris Kare matris mi.
	if (_det != (Type1)0 && _det != (Type1)999999) {
		unsigned int RC = this->row;
		unsigned int minor, zero;
		double division, cofactor;
		Matrix<double> root(RC, RC, 0.);
		Matrix<double> unit(RC, RC, 'e');
		for (unsigned int i = 0; i < RC; i++) {
			for (unsigned int j = 0; j < RC; j++) {
				root.setMtrx(i, j, this->Mtrx[i][j]);
			}
		}
		// alt kısmı ve üst kısmı sıfırlamak için 2 kez döndürüyoruz.
		for (int tur = 0; tur < 2; tur++) {
			for (minor = 0; minor < RC - 1; minor++) {
				zero = minor + 1;
				// Matrisin köşegen değerleri 0 ise satırları kendi içinde yer değiştiriyor
				if (root.getMtrx(minor, minor) == 0.0) {
					for (unsigned int i = zero; i < RC; i++) {
						if (root.getMtrx(i, minor) != 0.0) {
							for (unsigned int j = 0; j < RC; j++) {
								root.setArry(j, root.getMtrx(minor, j));
								root.setMtrx(minor, j, root.getMtrx(i, j));
								root.setMtrx(i, j, root.getArry(j));

								unit.setArry(j, unit.getMtrx(minor, j));
								unit.setMtrx(minor, j, unit.getMtrx(i, j));
								unit.setMtrx(i, j, unit.getArry(j));
							}
							i = RC;
						}
					}
				}
				// köşegen değerine göre çarpılan değer bulunup tüm satıra uygulandı.
				division = (1.0 / root.getMtrx(minor, minor));
				for (unsigned int i = 0; i < RC; i++) {
					double n = root.getMtrx(minor, i) * division;
					root.setMtrx(minor, i, n);
					n = unit.getMtrx(minor, i) * division;
					unit.setMtrx(minor, i, n);
				}
				// köşegen değerlerin altındaki tüm değerler sıfır(0) yapıldı.
				for (zero = minor + 1; zero < RC; zero++) {
					if (root.getMtrx(zero, minor) != 0.0) {
						cofactor = root.getMtrx(zero, minor) / root.getMtrx(minor, minor);
						if ((root.getMtrx(minor, minor) < 0.0 && root.getMtrx(zero, minor) > 0.0) ||
							(root.getMtrx(minor, minor) > 0.0 && root.getMtrx(zero, minor) < 0.0)) {
							for (unsigned int i = 0; i < RC; i++) {
								root.setArry(i, root.getMtrx(minor, i) * cofactor);
								unit.setArry(i, unit.getMtrx(minor, i) * cofactor);
							}
							for (unsigned int i = 0; i < RC; i++) {
								root.setMtrx(zero, i, root.getMtrx(zero, i) - root.getArry(i));
								unit.setMtrx(zero, i, unit.getMtrx(zero, i) - unit.getArry(i));
							}
						}
						else {
							for (unsigned int i = 0; i < RC; i++) {
								root.setArry(i, (-1 * root.getMtrx(minor, i) * cofactor));
								unit.setArry(i, (-1 * unit.getMtrx(minor, i) * cofactor));
							}
							for (unsigned int i = 0; i < RC; i++) {
								root.setMtrx(zero, i, root.getMtrx(zero, i) + root.getArry(i));
								unit.setMtrx(zero, i, unit.getMtrx(zero, i) + unit.getArry(i));
							}
						}
					}
					else {
						root.setMtrx(zero, minor, 0.0);
					}
				}
			}
			// Matrisin sütünda ortasına göre simetrisi alındı
			unsigned int length = RC;
			for (unsigned int y = 0; y < RC / 2; y++) {
				length--;
				for (unsigned int z = 0; z < RC; z++) {
					double changeT = root.getMtrx(z, y);
					double changeI = unit.getMtrx(z, y);
					root.setMtrx(z, y, root.getMtrx(z, length));
					root.setMtrx(z, length, changeT);
					unit.setMtrx(z, y, unit.getMtrx(z, length));
					unit.setMtrx(z, length, changeI);
				}
			}
			// Matrisin satırda ortasına göre simetrisi alındı
			length = RC;
			for (unsigned int y = 0; y < RC / 2; y++) {
				length--;
				for (unsigned int z = 0; z < RC; z++) {
					double changeT = root.getMtrx(y, z);
					double changeI = unit.getMtrx(y, z);
					root.setMtrx(y, z, root.getMtrx(length, z));
					root.setMtrx(length, z, changeT);
					unit.setMtrx(y, z, unit.getMtrx(length, z));
					unit.setMtrx(length, z, changeI);
				}
			}
		}
		for (unsigned int i = 0; i < RC; i++) {
			for (unsigned int j = 0; j < RC; j++) {
				this->Mtrx[i][j] = unit.getMtrx(i, j);
				//cout << unit.getMtrx(i, j) << " ";
			}   //cout << endl;
		}
		//cout << right << setfill('-') << setw(this->fill) << "\n";
	}
	else if (_det == (Type1)999999) {
		cout << "Kare Olmayan Matrisin Tersi Yoktur.\n";
		cout << right << setfill('-') << setw(this->fill) << "\n";
	}
	else if (_det == (Type1)0) {
		cout << "Determinanti Sifir(0) Matrisin Tersi Yoktur.\n";
		cout << right << setfill('-') << setw(this->fill) << "\n";
	}
	else {
		cout << "Bilinmeyen Bir Hata Olustu!\n";
		cout << right << setfill('-') << setw(this->fill) << "\n";
	}
}

/* ** Determinant Of Matrix Method With Gauss Jordan Rule ** */
template <class Type1>
Type1 Matrix<Type1>::det() {
	Type1 det = (Type1)1;
	// Matris Kare Matris mi?
	if (this->row == this->col) {
		unsigned int RC = this->row, minor;
		Matrix<double> root(RC, RC, (Type1)0);
		for (unsigned int i = 0; i < RC; i++) {
			for (unsigned int j = 0; j < RC; j++) {
				root.setMtrx(i, j, this->Mtrx[i][j]);
			}
		}
		// Matrisin Köşegen Değerlerinin altında kalan kısımları sıfır(0) yapıldı.
		// Eğer köşegen değeri 0 olan varsa başka bir satırla değiştirilip işleme devam edildi.
		for (minor = 0; minor < RC - 1; minor++) {
			for (unsigned int zero = minor + 1; zero < RC; zero++) {
				if (root.getMtrx(zero, minor) != 0.0) {
					if ((root.getMtrx(minor, minor) < 0.0 && root.getMtrx(zero, minor) > 0.0) ||
						(root.getMtrx(minor, minor) > 0.0 && root.getMtrx(zero, minor) < 0.0)) {
						for (unsigned int i = 0; i < RC; i++) {
							root.setArry(i, (root.getMtrx(minor, i) *
								(root.getMtrx(zero, minor) / root.getMtrx(minor, minor))
								)
							);
						}
						for (unsigned int i = 0; i < RC; i++) {
							root.setMtrx(zero, i, root.getMtrx(zero, i) - root.getArry(i));
							root.setArry(i, 0.0);
						}
					}
					else if (root.getMtrx(minor, minor) == 0.0) {
						for (unsigned int i = 0; i < RC; i++) {
							root.setArry(i, root.getMtrx(minor, i));
							root.setMtrx(minor, i, root.getMtrx(zero, i));
							root.setMtrx(zero, i, (-1 * root.getArry(i)));
						}
						for (unsigned int i = 0; i < RC; i++) {
							root.setArry(i, (-1 * (root.getMtrx(minor, i) *
								(root.getMtrx(zero, minor) / root.getMtrx(minor, minor))
								)));
						}
						for (unsigned int i = 0; i < RC; i++) {
							root.setMtrx(zero, i, root.getMtrx(zero, i) + root.getArry(i));
							root.setArry(i, 0.0);
						}
					}
					else {
						for (unsigned int i = 0; i < RC; i++) {
							root.setArry(i, (-1 * (root.getMtrx(minor, i) *
								(root.getMtrx(zero, minor) / root.getMtrx(minor, minor))
								)));

						}
						for (unsigned int i = 0; i < RC; i++) {
							root.setMtrx(zero, i, root.getMtrx(zero, i) + root.getArry(i));
							root.setArry(i, 0.0);
						}
					}
				}
				else {
					root.setMtrx(zero, minor, 0.0);
				}
			}
		}
		// Matrisin Köşegen değerleri Çarpılarak Determinant bulundu.
		for (unsigned int i = 0; i < RC; i++) {
			//for (int j = 0; j < length; j++) {
			//cout << fixed << setprecision(2) << temporaryM[i][j] << "\t";
			//} //cout << endl;
			det *= root.getMtrx(i, i);
		}
		// Fonksiyon İçinde Oluşturulan Yardımcı matris ve Dizi silindi.
		this->determinant = det;
		return det;
	}
	else {
		this->determinant = 999999;
		return (Type1)999999;
	}
}

/* ** Matrix Print Method Without Parameters ** */
template <class Type1>
void Matrix<Type1>::print() {
	for (unsigned int j = 0; j <= col; j++)
		if (j == 0) cout << this->row << "x" << this->col << "\t";
		else cout << j - 1 << "\t";
		cout << endl;
		for (unsigned int j = 0; j <= this->col; j++)
			if (j == 0)
				cout << "\t";
			else cout << "-\t";
			cout << endl;
			for (unsigned int i = 0; i < this->row; i++) {
				cout << i << "|\t";
				for (unsigned int j = 0; j < this->col; j++) {
					cout << fixed << setprecision(2) << this->Mtrx[i][j] << "\t";
				}cout << endl;
			}
			cout << right << setfill('-') << setw(this->fill) << "\n";
}

/* ** Matrix Print File Method With File Parameter ** */
template <class Type1>
void Matrix<Type1>::print(string _file) {
	file = _file;
	ofstream outfile;
	outfile.open(file, ios::app);
	for (unsigned int i = 0; i < this->row; i++) {
		for (unsigned int j = 0; j < this->col; j++) {
			outfile << this->Mtrx[i][j] << "\t";
		}   outfile << "\n";
	}
	outfile << right << setfill('-') << setw(col * 4) << '\n';
	outfile.close();
}

/* ** Matrix Print File Clear Inside Helper Method With File Parameter ** */
template <class Type1>
void Matrix<Type1>::clear(string _file) {
	file = _file;
	ofstream clear;
	clear.open(file, ios::trunc);
	clear << "";
	clear.close();
}

/* ** Matrix Print Determinant Helper Method ** */
template <class Type1>
void Matrix<Type1>::print(Type1 _det) {
	if (this->det() == (Type1)999999) {
		cout << " * Kare olmayan Matrisin Determinanti Soz Konusu Degildir!\n";
		cout << right << setfill('-') << setw(this->fill) << "\n";
	}
	else {
		cout << "Determinant = " << fixed << setprecision(2) << this->det() << endl;
		cout << right << setfill('-') << setw(this->fill) << "\n";
	}
}

/* ** Destructor Method ** */
template <class Type1>
Matrix<Type1>::~Matrix() {
	//cout << "yıkıcı çalıştı" << endl ;
	/*for(int i =0; i < row; i++)
	delete [] Mtrx[i];
	delete [] Mtrx;*/
}

/* **************** Image.h **************** */
//#include "Matrix.h"
// RGB türünden Struct Yapısı Oluşturuldu.


// Image Sınıfı Matrix Base Class ından ve RGB Struct Yapısından Miras Aldı.
template <class Type2>
class Image : public Matrix<Type2> {
public:
	struct RGB {
		// r(red) g(green) b(blue) a(opacity) değeri içindir.
		int r, g, b;
		double a;
	};
	/* ** Image Class Of Constructor Without Parameter and With Parameters ** */
	Image(int _height = 255, int _width = 255, Type2 _pixVal = 0);

	/* ** Image Class Of Constructor With Parameters Read File ** */
	Image(string filename, string format);

	/* ** Image Read File Method. Tested ** */
	void imRead(string filename, string format);

	/* ** Image Write File Method. Tested ** */
	void imWrite(string filename, string format);

	/* ** Image Status Helper Method. Tested ** */
	void Gray_BW();

	/* ** Convert Color Image to Gray level Method. Tested ** */
	void color2gray();

	/* ** Convert Gray Level Image to Binary With Given Threshold Method. Tested ** */
	void gray2Binary(int thr);

	/* ** Morphological Operation Erosion Method. Tested ** */
	void erosion();

	/* ** Morphological Operation Dilation Method. Tested ** */
	void dilation();

	/* ** Morphological Operation Opening Method. Tested ** */
	void opening();

	/* ** Morphological Operation Closing Method. Tested ** */
	void closing();

	/* ** Image Matrix Write On Console With print() Method. Tested ** */
	void print();

	/* ** Destructor Method ** */
	~Image();
private:
	void CreateRGB() {
		RGBA = new Image<int>::RGB *[h];
		for (unsigned int i = 0; i < h; i++) {
			RGBA[i] = new Image<int>::RGB[w];
		}
		for (unsigned int i = 0; i < h; i++) {
			for (unsigned int j = 0; j < w; j++) {
				RGBA[i][j].r = 0;
				RGBA[i][j].g = 0;
				RGBA[i][j].b = 0;
				RGBA[i][j].a = 1.0;
			}
		}
	}
	unsigned int w, h;
	int GrayBW = 0;
	streampos size;
	// Dosya Okuma ve Yazma İşlemleri İçin Yardımcı Arrayler Tanımlandı.
	char *memblock, *buffer;
	char bfsize, bfoffset, bppixel;
	int	 padding, colorTable;
	RGB **RGBA;
};
/* **Image.cpp** */
//#include "Image.h"

/* ** Image Class Of Constructor Without Parameter and With Parameters ** */
template <class Type2>
Image<Type2>::Image(int _height, int _width, Type2 _pixVal)
	: Matrix<Type2>(_height, _width, _pixVal) {
	h = _height;
	w = _width;
	CreateRGB();
}

/* ** Image Class Of Constructor With Parameters Read File ** */
template <class Type2>
Image<Type2>::Image(string filename, string format) : Matrix<Type2>(255, 255, (Type2)0) {
	ifstream file(filename, ios::in | ios::binary | ios::ate);
	if (format == "bin") {
		if (file.is_open()) {
			size = file.tellg();
			memblock = new char[2];
			file.seekg(0, ios::beg);
			file.read(memblock, 2);
			w = (int(memblock[0]) + 256) % 256;
			h = (int(memblock[1]) + 256) % 256;
			//Matrix<int> tempr(h, w, 0);
			//temp.resize(h, w);
			//this->row = h;
			//this->col = w;
			CreateRGB();
			delete memblock;
			memblock = new char[1];
			file.seekg(2, ios::beg);
			for (unsigned int i = 0; i < h; i++) {
				for (unsigned int j = 0; j < w; j++) {
					file.read(memblock, 1);
					RGBA[i][j].r = (int(memblock[0]) + 256) % 256;
					//RGBA[i][j].g = (int(memblock[0]) + 256) % 256;
					//RGBA[i][j].b = (int(memblock[0]) + 256) % 256;
				}
			}
			file.close(); //cout << "Tum Dosya Icerigi Hafizada!";
			delete memblock;
		}
		else {
			cout << "Dosya Acilamadi.";
		}

	}
	else if (format == "bmp") {
		if (file.is_open()) {
			/* **Header Values** */
			memblock = new char[54];
			buffer = new char[1078];
			file.seekg(0, ios::beg);
			file.read(memblock, 54);
			for (int i = 0; i < 54; i++) {
				buffer[i] = memblock[i];
			}
			bfsize = memblock[2];
			bfoffset = memblock[10];
			w = (int(memblock[18]) + 256) % 256;
			h = (int(memblock[22]) + 256) % 256;
			bppixel = memblock[28];
			padding = 4 - (3 * w) % 4;
			if (padding == 4) padding = 0;
			delete memblock;

			/* **Color Table Control** */
			file.seekg(0, ios::end);
			size = file.tellg();
			int colorTableControl1 = 0;
			int colorTableControl2 = 1;
			file.seekg(54, ios::beg);
			memblock = new char[4];
			for (int i = 0; i < 64; i++) {
				file.read(memblock, 4);
				if ((int(memblock[0]) + 256) % 256 == colorTableControl1)
					colorTableControl2 = 1;
				else
					colorTableControl2++;
				colorTableControl1++;
			}
			delete memblock;
			if (colorTableControl2 == 1) {
				this->colorTable = 1;
				memblock = new char[1024];
				file.seekg(54, ios::beg);
				file.read(memblock, 1024);
				for (int i = 54; i < 1078; i++) {
					buffer[i] = memblock[i - 54];
				}
				delete memblock;
				file.seekg(1078, ios::beg);
			}
			else {
				this->colorTable = 0;
				file.seekg(54, ios::beg);
			}
			/* **RGB Values** */
			memblock = new char[3];
			CreateRGB();
			for (unsigned int i = 0; i < h; i++) {
				for (unsigned int j = 0; j < w; j++) {
					file.read(memblock, 3);
					RGBA[i][j].r = (int(memblock[0]) + 256) % 256;
					RGBA[i][j].g = (int(memblock[1]) + 256) % 256;
					RGBA[i][j].b = (int(memblock[2]) + 256) % 256;
				} file.seekg(padding, ios::cur);
			}
			delete memblock;
			file.close();

		}
		else { cout << "Dosya Acilamadi.\n"; }
	}
	else { cout << "Dosya formati Uygun Degil!\n"; }
}

/* ** Image Read File Method. Tested ** */
template <class Type2>
void Image<Type2>::imRead(string filename, string format) {
	ifstream file(filename, ios::in | ios::binary | ios::ate);
	if (format == "bin") {
		if (file.is_open()) {
			size = file.tellg();
			memblock = new char[2];
			file.seekg(0, ios::beg);
			file.read(memblock, 2);
			w = (int(memblock[0]) + 256) % 256;
			h = (int(memblock[1]) + 256) % 256;
			Matrix<int> temp;
			temp.resize(h, w);
			this->row = h;
			this->col = w;
			CreateRGB();
			delete memblock;
			memblock = new char[1];
			file.seekg(2, ios::beg);
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					file.read(memblock, 1);
					RGBA[i][j].r = (int(memblock[0]) + 256) % 256;
					RGBA[i][j].g = (int(memblock[0]) + 256) % 256;
					RGBA[i][j].b = (int(memblock[0]) + 256) % 256;
				}
			}
			file.close(); //cout << "Tum Dosya Icerigi Hafizada!";
			delete memblock;
		}
		else {
			cout << "Dosya Acilamadi.";
		}

	}
	else if (format == "bmp") {
		if (file.is_open()) {
			/* **Header Values** */
			memblock = new char[54];
			buffer = new char[1078];
			file.seekg(0, ios::beg);
			file.read(memblock, 54);
			for (int i = 0; i < 54; i++) {
				buffer[i] = memblock[i];
			}
			bfsize = memblock[2];
			bfoffset = memblock[10];
			w = (int(memblock[18]) + 256) % 256;
			h = (int(memblock[22]) + 256) % 256;
			bppixel = memblock[28];
			padding = 4 - (3 * w) % 4;
			if (padding == 4) padding = 0;
			delete memblock;

			/* **Color Table Control** */
			file.seekg(0, ios::end);
			size = file.tellg();
			int colorTableControl1 = 0;
			int colorTableControl2 = 1;
			file.seekg(54, ios::beg);
			memblock = new char[4];
			for (int i = 0; i < 64; i++) {
				file.read(memblock, 4);
				if ((int(memblock[0]) + 256) % 256 == colorTableControl1)
					colorTableControl2 = 1;
				else
					colorTableControl2++;
				colorTableControl1++;
			}
			delete memblock;
			if (colorTableControl2 == 1) {
				this->colorTable = 1;
				memblock = new char[1024];
				file.seekg(54, ios::beg);
				file.read(memblock, 1024);
				for (int i = 54; i < 1078; i++) {
					buffer[i] = memblock[i - 54];
				}
				delete memblock;
				file.seekg(1078, ios::beg);
			}
			else {
				this->colorTable = 0;
				file.seekg(54, ios::beg);
			}
			/* **RGB Values** */
			memblock = new char[3];
			CreateRGB();
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					file.read(memblock, 3);
					RGBA[i][j].r = (int(memblock[0]) + 256) % 256;
					RGBA[i][j].g = (int(memblock[1]) + 256) % 256;
					RGBA[i][j].b = (int(memblock[2]) + 256) % 256;
				} file.seekg(padding, ios::cur);
			}
			delete memblock;
			file.close();

		}
		else { cout << "Dosya Acilamadi.\n"; }
	}
	else { cout << "Dosya formati Uygun Degil!\n"; }
}

/* ** Image Write File Method. Tested ** */
template <class Type2>
void Image<Type2>::imWrite(string filename, string format) {
	if (format == "bin") {
		ofstream outfile(filename, ios::in | ios::binary | ios::out);
		outfile << char(w);
		outfile << char(h);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				outfile << char(RGBA[i][j].r);
				//outfile << char(RGBA[i][j].g);
				//outfile << char(RGBA[i][j].b);
			}
		}
		outfile.close();
		delete RGBA;
	}
	else if (format == "bmp") {
		ofstream outfile(filename, ios::in | ios::binary | ios::out);
		if (this->colorTable == 1) {
			for (int i = 0; i < 1078; i++) {
				outfile << buffer[i];
			}
		}
		else {
			for (int i = 0; i < 54; i++) {
				outfile << buffer[i];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				outfile.write((char*)&RGBA[i][j].r, 1);
				outfile.write((char*)&RGBA[i][j].g, 1);
				outfile.write((char*)&RGBA[i][j].b, 1);
			}	outfile.seekp(padding, ios::cur);
		}
		outfile.close();
		delete buffer;
		delete RGBA;
	}
	else { cout << "Format Taninmadi!\n"; }
}

/* ** Convert Color Image to Gray level Method. Tested ** */
template <class Type2>
void Image<Type2>::color2gray() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			int m = (int)RGBA[i][j].r + (int)RGBA[i][j].g + (int)RGBA[i][j].b;
			m /= 3;
			RGBA[i][j].r = m;
			RGBA[i][j].g = m;
			RGBA[i][j].b = m;
		}
	}
}

/* ** Image Status Helper Method. Tested ** */
template <class Type2>
void Image<Type2>::Gray_BW() {
	int _r, _g, _b;
	if (GrayBW == 0) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				_r = (int)RGBA[i][j].r;
				_g = (int)RGBA[i][j].g;
				_b = (int)RGBA[i][j].b;
				if (_r == _g && _g == _b) GrayBW = 1;
				else { GrayBW = 0; break; }
			}
		}
	}
	else if (GrayBW == 1) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				_r = (int)RGBA[i][j].r;
				_g = (int)RGBA[i][j].g;
				_b = (int)RGBA[i][j].b;
				if ((_r == 0 || _r == 255) && (_g == 0 || _g == 255) &&
					(_b == 0 || _b == 255)) GrayBW = 2;
				else { GrayBW = 0; break; }
			}
		}
	}
	else if (GrayBW == 2) {}
	else { cout << "Gri Olmayan Resim Siyah Beyaz Yapilamaz\n"; }
}

/* ** Convert Gray Level Image to Binary With Given Threshold Method. Tested ** */
template <class Type2>
void Image<Type2>::gray2Binary(int thr) {
	Gray_BW();
	if (GrayBW == 1) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if ((int)RGBA[i][j].r < thr) {
					RGBA[i][j].r = 0;
					RGBA[i][j].g = 0;
					RGBA[i][j].b = 0;
				}
				else {
					RGBA[i][j].r = 255;
					RGBA[i][j].g = 255;
					RGBA[i][j].b = 255;
				}
			}
		}
	}
	else cout << "Image Is Not Gray\n";
}

/* ** Morphological Operation Erosion Method. Tested ** */
template <class Type2>
void Image<Type2>::erosion() {
	Gray_BW();
	int **mask;
	mask = new int *[h];
	for (int i = 0; i < h; i++) {
		mask[i] = new int[w];
	}
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			mask[i][j] = 255;
	if (GrayBW == 2) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (RGBA[i][j].r == 0) {
					if (i != 0 && j != 0 && j != w - 1 && i != h - 1 &&
						RGBA[i - 1][j].r == 0 && RGBA[i][j - 1].r == 0 &&
						RGBA[i][j + 1].r == 0 && RGBA[i + 1][j].r == 0)
					{
						mask[i][j] = 0;
					}
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				RGBA[i][j].r = mask[i][j];
				RGBA[i][j].g = mask[i][j];
				RGBA[i][j].b = mask[i][j];
			}
		}
	}
	else {
		cout << "Image Is Not Black&White For Erosion\n";
	}
	delete mask;
}

/* ** Morphological Operation Dilation Method. Tested ** */
template <class Type2>
void Image<Type2>::dilation() {
	Gray_BW();
	int **mask;
	mask = new int *[h];
	for (int i = 0; i < h; i++) {
		mask[i] = new int[w];
	}
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			mask[i][j] = 255;
	if (GrayBW == 2) {
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (RGBA[i][j].r == 0) {
					if (i != 0) { mask[i - 1][j] = 0; }
					if (j != 0) { mask[i][j - 1] = 0; }
					if (j != w - 1) { mask[i][j + 1] = 0; }
					if (i != h - 1) { mask[i + 1][j] = 0; }
				}
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				RGBA[i][j].r = mask[i][j];
				RGBA[i][j].g = mask[i][j];
				RGBA[i][j].b = mask[i][j];
			}
		}
	}
	else {
		cout << "Image Is Not Black&White For Dilation\n";
	}
	delete mask;
}

/* ** Morphological Operation Opening Method. Tested ** */
template <class Type2>
void Image<Type2>::opening() {
	erosion();
	dilation();
}

/* ** Morphological Operation Closing Method. Tested ** */
template <class Type2>
void Image<Type2>::closing() {
	dilation();
	erosion();
}

/* ** Image Matrix Write On Console With print() Method. Tested ** */
template <class Type2>
void Image<Type2>::print() {
	int k = 0;
	for (int i = 0; i < 1; i++) {
		cout << endl;
		for (int j = 0; j < w; j++) {
			k++;
			cout << k << ". pixel: " << this->Mtrx[i][j]
				<< " " << Image::RGBA[i][j].r
				<< " " << Image::RGBA[i][j].g
				<< " " << Image::RGBA[i][j].b << "\n";
		}
	}
}

/* ** Destructor Method ** */
template <class Type2>
Image<Type2>::~Image() {}

/* *********** Table.h ************ */
#include <string>

template <class Type3>
class Table : public Matrix<Type3> {
public:
	/* ** Table Class Inheritance Matrix Class and Inheritance Constructor Method. Tested ** */
	Table(const int _TRow = 10, const int _TCol = 10, Type3 _TVal = 0);
	
	Table operator=(const Table& m);

	Table operator=(Matrix<Type3>& m);

	/* ** Return the Value at [r,c] Index Method. Tested ** */
	Type3 itemAt(int, int);

	/* ** Return the Value at itemAt(string _s) Index Method. Tested ** */
	Type3 itemAt(string);

	/* ** Return the Value at itemAt(string rs, string cs) Index Method. Tested ** */
	Type3 itemAt(string rs, string cs);

	/* ** Update Row Name setRowNames(string s[], int n) Method. Tested ** */
	void setRowNames(string s[], int n);

	/* ** Update Column Name setColNames(string s[], int n) Method. Tested ** */
	void setColNames(string s[], int n);

	/* ** Table Matrix Write On Console With print() and With Special Name Method. Tested ** */
	void print();

	/* ** Destructor Method ** */
	~Table();
private:
	void CreateTable() {
		RowName = new string[17576];
		if (this->col <= 26) ColName = new string[26];
		else if (this->col > 26 && this->col <= 676) ColName = new string[676];
		else ColName = new string[17576];
		Cha1 = new string[26];
		int cN = 65;
		for (int i = 0; i < 17576; i++) {
			RowName[i] = to_string(i);
		}
		for (int i = 0; i < 26; i++) {
			Cha1[i] = char(cN);
			ColName[i] = Cha1[i];
			cN++;
		} cN = 26;
		if (this->col > 25) {
			for (int i = 1; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					ColName[cN] = Cha1[i] + Cha1[j];
					cN++;
				}
			}
		}
		if (this->col > 676) {
			for (int i = 1; i < 26; i++) {
				for (int j = 0; j < 26; j++) {
					for (int k = 0; k < 26; k++) {
						ColName[cN] = Cha1[i] + Cha1[j] + Cha1[k];
						cN++;
					}
				}
			}
		}
	}
	std::string *RowName, *ColName, *Cha1;
};

/* ************ Table.cpp ************ */

/* ** Table Class Inheritance Matrix Class and Inheritance Constructor Method. Tested ** */
template <class Type3>
Table<Type3>::Table(const int _TRow, const int _TCol, Type3 _TVal)
	: Matrix<Type3>(_TRow, _TCol, _TVal) {
	CreateTable();
	if (_TVal == 'e') {
		for (int i = 0; i < _TRow; i++) {
			for (int j = 0; j < _TCol; j++) {
				this->Mtrx[i][j] = (Type3)0;
			}
		}
	}
}


template <class Type3>
Table<Type3> Table<Type3>::operator=(const Table& m){
	int i, j;
	this->row = m.row;
	this->col = m.col;
	Table<Type3> temp(this->row, this->col, (Type3)0);
	this->Create();
	for (i = 0; i < this->row; i++) {
		for (j = 0; j < this->col; j++) {
			this->Mtrx[i][j] = m.Mtrx[i][j];
			temp.Mtrx[i][j] = this->Mtrx[i][j];
		}
	}
	return temp;
}
template <class Type3>
Table<Type3> Table<Type3>::operator=(Matrix<Type3>& m) {
	int i, j;
	i = m.getRow();
	j = m.getCol();
	Table<Type3> temp(i, j, (Type3)0);
	this->setRowCol(i, j);
	this->Create();
	for (i = 0; i < m.getRow(); i++) {
		for (j = 0; j < m.getCol(); j++) {
			this->setMtrx(i, j, m.getMtrx(i, j));
			temp.Mtrx[i][j] = m.getMtrx(i, j);
		}
	}
	return temp;
}

/* ** Return the Value at [r,c] Index Method. Tested ** */
template <class Type3>
Type3 Table<Type3>::itemAt(int _r, int _c) {
	return this->Mtrx[_r][_c];
}

/* ** Return the Value at itemAt(string _s) Index Method. Tested ** */
template <class Type3>
Type3 Table<Type3>::itemAt(string _s) {
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			string nameRC = ColName[j] + RowName[i];
			if (nameRC == _s) {
				return this->Mtrx[i][j];
			}
		}
	}
	return 0;
}

/* ** Return the Value at itemAt(string rs, string cs) Index Method. Tested ** */
template <class Type3>
Type3 Table<Type3>::itemAt(string rs, string cs) {
	string swap = cs + rs;
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			string nameRC = ColName[j] + RowName[i];
			if (nameRC == swap) {
				return this->Mtrx[i][j];
			}
		}
	}
	return 0;
}

/* ** Update Row Name setRowNames(string s[], int n) Method. Tested ** */
template <class Type3>
void Table<Type3>::setRowNames(string s[], int n) {
	for (int i = 0; i < n; i++) {
		RowName[i] = s[i];
	}
}

/* ** Update Column Name setColNames(string s[], int n) Method. Tested ** */
template <class Type3>
void Table<Type3>::setColNames(string s[], int n) {
	for (int i = 0; i < n; i++) {
		ColName[i] = s[i];
	}
}

/* ** Table Matrix Write On Console With print() and With Special Name Method. Tested ** */
template <class Type3>
void Table<Type3>::print() {
	string MtrxName = to_string(this->row) + "x" + to_string(this->col);
	for (int j = 0; j < this->col; j++) {
		if (j == 0) {
			cout << right << setw(8) << MtrxName << "|";
		}
		if (ColName[j].length() <= 4) {
			cout << right << setw(4) << ColName[j] << " ";
		}
		else {
			string colString = ColName[j];
			for (int k = 0; k < 4; k++)
				cout << colString[k];
			cout << " ";
		}
	}
	cout << endl;
	cout << setfill('-') << setw((this->col + 2) * 5) << "" << endl << setfill(' ');
	for (int i = 0; i < this->row; i++) {
		if (RowName[i].length() <= 8) {
			cout << right << setw(8) << RowName[i] << "|";
		}
		else {
			string rowString = RowName[i];
			for (int k = 0; k < 8; k++)
				cout << rowString[k];
			cout << "|";
		}
		for (int j = 0; j < this->col; j++) {
			cout << right << setw(4) << fixed << setprecision(2) << this->Mtrx[i][j] << " ";
		}
		cout << endl;
	}
	cout << setfill('-') << setw((this->col + 2) * 5) << "" << endl << setfill(' ');
}

/* ** Destructor Method ** */
template <class Type3>
Table<Type3>::~Table() {}


int main() {
	/* ** Matrix Class Pointer Object Created ** */
	//Integer Default 10x10 0 Değerli Matris
	Matrix<int>		*m1 = new Matrix<int>();
	//Integer 5x5 3 Değerli Matris			
	Matrix<double>		*m2 = new Matrix<double>(4, 4, 3);
	//Integer 5x5 3 Değerli Matris	
	Matrix<double>	*m3 = new Matrix<double>(4, 4, 2);
	//Integer 6x6 Birim Matris
	Matrix<double>	*m4 = new Matrix<double>(4, 4, 'e');
	//Integer 6x6 0-255 Random Değerli Matris
	Matrix<double>	*m5 = new Matrix<double>(4, 4, 'r');
	//Integer 6x4 0-255 Random Değerli Matris	
	Matrix<double>		*m6 = new Matrix<double>(6, 4, 'r');
	//Char 4x6 '*' Değerli Matris	
	Matrix<char>	*m7 = new Matrix<char>(4, 6, '*');

	/* ** Matrix Write On Console With print() Method. Tested ** */
	//m1->print();
	//m2->print();
	//m3->print();
	//m4->print();
	//m5->print();
	//m6->print();
	//m7->print();

	/* ** Matrix Resize With resize(int, int) Method. Tested ** */
	//m7->resize(9, 5);		m7->print();
	//m4->resize(9, 5);		m4->print();

	/* ** Matrix Overloading For Matrix Operations. Tested ** */
	//*m2 = *m5 + *m3;		m2->print();
	//*m2 = *m5 * *m3;		m2->print();
	//*m2 = *m5 - *m3;		m2->print();

	/* ** Matrix Overloading For Scalar Operations. Tested ** */
	//*m2 = *m2 + 10;		m2->print();
	//*m2 = *m2 - 20;		m2->print();
	//*m2 = *m2 * 2;		m2->print();
	//*m2 = *m2 / 1;		m2->print();
	//*m2 = *m2 % 6;		m2->print();
	//*m2 = *m2 ^ 2;		m2->print();

	/* ** Matrix Write On File With print(string) Method. Tested ** */
	//m4->clear("Matrix.txt");
	//m2->print("Matrix.txt");
	//m3->print("Matrix.txt");
	//m4->print("Matrix.txt");

	/* ** Take Matrix Transpoze With T() Method. Tested ** */
	//m5->T();				m5->print();

	/* ** Matrix Elementwise Multiply With emul(Object) Method. Tested ** */
	//m5->emul(*m6);		m5->print();

	/* ** Determinant of Matrix With det() Method. Tested ** */
	//m5->print(m5->det());

	/* ** Matrix Inversion if Available With inv() Method. Tested ** */
	//m5->print();
	//m5->print(m4->det());
	//m5->print();
	//*m3 = *m5 + 0;
	//m3->print();
	//m5->inv();
	//m5->print();
	//m5->emul(*m3);
	//m5->print();

	/* ** Image Class Pointer Object Created ** */
	Image<int> *i1 = new Image<int>();
	Image<int> *i2 = new Image<int>(5, 8, 0);
	Image<int> *i3 = new Image<int>("image1.bin", "bin");
	Image<int> *i4 = new Image<int>("image_file1.bmp", "bmp");

	/* ** Matrix Write On Console With print() Method. Tested ** */
	//i1->Matrix::print();
	//i2->Matrix::print();

	/* ** Image Read and Write File Method. Tested ** */
	//i3->imRead("image2.bin", "bin");
	//i3->imWrite("newImage1.bin", "bin");
	//i4->imRead("Images3.bmp", "bmp");
	//i4->imWrite("newImage1.bmp", "bmp");

	/* ** Convert Color Image to Gray level Method. Tested ** */
	//i4->color2gray();
	//i4->imWrite("newImage1.bmp", "bmp");

	/* ** Convert Gray Level Image to Binary With Given Threshold Method. Tested ** */
	//i4->gray2Binary(128);
	//i4->imWrite("newImage1.bmp", "bmp");

	/* ** Morphological Operations Methods. Tested ** */
	//i4->dilation();
	//i4->imWrite("newImageD.bmp", "bmp");
	//i4->erosion();
	//i4->imWrite("newImageE.bmp", "bmp");
	//i4->opening();
	//i4->imWrite("newImageO.bmp", "bmp");
	//i4->closing();
	//i4->imWrite("newImageC.bmp", "bmp");

	/* ** Table Class Pointer Object Created ** */
	Table<int> *t1 = new Table<int>();
	Table<int> *t2 = new Table<int>(7, 6, 9);
	Table<double> *t3 = new Table<double>(7, 7, 'r');
	Table<int> *t4 = new Table<int>(5, 5, 'e');
	Table<double> *t5 = new Table<double>(4, 4, 'r');

	/* ** Matrix Write On Console With print() Method. Tested ** */
	//t1->print();
	//t2->print();
	//t2->resize(10, 10);
	//t2->print();
	//t3->print();
	//t5->print();
	//t4->print();

	//t3->print();
	//t5->print();
	//cout << t3->det() << endl;
	//t3->print();
	//*t3 = *m5;
	//t3->print();
	//*t3 = *t5;
	//t3->print();
	//t5->print();
	//t3->inv();
	//t3->print();
	//t3->emul(*t5);
	//t3->print();

	/* ** Return at Value [row][col] Method. Tested ** */
	//cout << "4, 2 :" << t3->itemAt(4, 2) << endl;
	//cout << "C4 :" << t3->itemAt("C4") << endl;
	//cout << "4, C :" << t3->itemAt("4", "C") << endl;

	/* ** Update RowName and ColName Method. Tested ** */
	//string rs[] = { "0. Satir",  "1. Satir", "2. Satir", "3. Satir", "4. Satir" };
	//t3->setRowNames(rs, 5);
	//cout << "4. Satir, C :" << t3->itemAt("4. Satır", "C") << endl;
	//string cs[] = { "0. Sutun",  "1. Sutun", "2. Sutun", "3. Sutun", "4. Sutun" };
	//t3->setColNames(cs, 5);
	//cout << "4. Satir, 2. Sutun :" << t3->itemAt("4. Satır", "2. Sutun") << endl << endl;
	//t3->print();

	/* ** Delete Pointer Objects With delete. Tested ** */
	delete m1;
	delete m2;
	delete m3;
	delete m4;
	delete m5;
	delete m6;
	delete m7;
	delete i1;
	delete i2;
	delete i3;
	delete i4;
	delete t1;
	delete t2;
	delete t3;
	delete t4;
	delete t5;

	system("PAUSE");
	return 0;
}
/* **************************************************************************************************
Dosyayı.cpp olarak kaydedin.Şimdi dosyanın olduğu yere konsoldan cd komutunu kullanarak ilerleyin.
Eğer dosyanın adini unuttuysanız –ls komutunu kullanarak klasördeki tüm dosyalara bakabilirsiniz.

Derlemek için aşağıdaki komutu yazın ve enter’a basın.

g++ dosya_adi.cpp –o dosya_adi

şimdi kodunuzda hata yok ise programınız hazırdır ve dosya_adi olarak derlenmiştir.Bu programı açmak için

. / dosya_adi

Yazmanız yeterli.
************************************************************************************************** */
