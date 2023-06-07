#include<iostream>
#include<vector>

class Matrix {
private:
	int row = 0, col = 0;
	std::vector<std::vector<int>>arr;
public:
	Matrix() {
	}

	Matrix(int row, int col) {
		this->row = row;
		this->col = col;
	}

	Matrix(int row, int col, std::vector<std::vector<int>>arr) {
		this->row = row;
		this->col = col;
		this->arr = arr;
	}

	void setRow(int row) {
		this->row = row;
	}

	int getRow() {
		return this->row;
	}

	void setCol(int col) {
		this->col = col;
	}

	int getCol() {
		return this->col;
	}

	void setMatrix() {
		if (row == 0) {
			std::cout << "Enter row: ";
			std::cin >> row;
		}
		if (col == 0) {
			std::cout << "Enter col: ";
			std::cin >> col;
		}
		arr.resize(row);
		for (int i = 0; i < row; ++i) {
			std::vector<int>arr1(col);
			for (int j = 0; j < col; ++j) {
				std::cin >> arr1[j];
			}
			arr[i] = arr1;
		}
	}

	std::vector<std::vector<int>> getMatrix() {
		return arr;
	}
	
	void showMatrix() {
		for (int i = 0; i < (int)arr.size(); ++i) {
			for (int j = 0; j < (int)arr[i].size(); ++j) {
				std::cout << arr[i][j]<<" ";
			}
			std::cout << "\n";
		}
	}

};
class MutilMatrix {
private:
	int row1, col1, row2, col2;
	std::vector<std::vector<int>>arr1;
	std::vector<std::vector<int>>arr2;
public:

	MutilMatrix() {
	}

	MutilMatrix(Matrix* mt1, Matrix* mt2) {
		row1 = mt1->getRow();
		row2 = mt2->getRow();
		col1 = mt1->getCol();
		col2 = mt2->getCol();
		arr1 = mt1->getMatrix();
		arr2 = mt2->getMatrix();
	}

	bool Check() {
		if (col1 == row2) {
			return true;
		}
		return false;
	}

	std::vector<std::vector<int>> ResultMulti() {
		std::vector<std::vector<int>> result;
		int count = 0;
		if (Check()) {
			for (int i = 0; i < row1; ++i) {
				std::vector<int>tmp;
				for (int j = 0; j < col2; ++j) {
					int sum = 0;
					for (int k = 0; k < col1; ++k) {
						sum += arr1[i][k] * arr2[k][j];
					}
					tmp.push_back(sum);
				}
				result.push_back(tmp);
			}
		}
		return result;
	}

};

int main()
{
	std::vector<std::vector<int>>arr = { {1,2,3},{4,5,6} };
	std::vector<std::vector<int>>arr1 = { {3,6,7}, {8,9,10}, {3,6,9} };
	Matrix* mt = new Matrix(arr.size(), arr[0].size(), arr);
	Matrix* mt1 = new Matrix(arr1.size(), arr1[0].size(), arr1);

	MutilMatrix* ml = new MutilMatrix(mt, mt1);
	ml->Check();
	std::vector<std::vector<int>>result =  ml->ResultMulti();
	for (int i = 0; i < (int)result.size(); ++i) {
		for (int j = 0; j < (int)result[i].size(); ++j) {
			std::cout << result[i][j] << " ";
		}
		std::cout << "\n";
	}
	delete mt, mt1, ml;
	return 0;
}