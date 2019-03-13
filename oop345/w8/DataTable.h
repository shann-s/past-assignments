#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <math.h>

namespace w8
{
	template<class T>
	class DataTable
	{
		std::vector<T> xAxis, yAxis;
		int fieldW, dec;
	public:
		DataTable(std::ifstream&, int, int);
		~DataTable();
		T mean() const;
		T sigma() const;
		T median() const;
		void regression(T& slope, T& y_intercept) const;
		void display(std::ostream&) const;
	};

	template<class T> DataTable<T>::DataTable(std::ifstream& dataFile, int FW, int ND)
	{
		fieldW = FW;
		dec = ND;
		while (!dataFile.eof())
		{
			T tmp;
			T tmp2;
			dataFile >> tmp;
			dataFile >> tmp2;
			xAxis.push_back(tmp);
			yAxis.push_back(tmp2);
		}
		dataFile.close();
	}

	template<class T> DataTable<T>::~DataTable()
	{
		xAxis.clear();
		yAxis.clear();
	}
	template<class T> T DataTable<T>::mean() const
	{
		return std::accumulate(yAxis.begin(), yAxis.end(), T(0)) / yAxis.size();
	}
	template<class T> T DataTable<T>::sigma() const
	{
		T meanY = mean();
		T ssd = std::accumulate(yAxis.begin(), yAxis.end(), T(0), [=](T y, T current) {return y += pow((current - meanY), 2); });
		return sqrt(ssd / (yAxis.size() - 1));
	}

	template<class T> T DataTable<T>::median() const
	{
		return yAxis[(yAxis.size() / 2) - 1];
	}

	template<class T> void DataTable<T>::regression(T& slope, T& y_intercept) const
	{
		T sumX = std::accumulate(xAxis.begin(), xAxis.end(), T(0));
		T sumY = std::accumulate(yAxis.begin(), yAxis.end(), T(0));
		T eXY = std::inner_product(xAxis.begin(), xAxis.end(), yAxis.begin(), T(0));
		T eX2 = std::accumulate(xAxis.begin(), xAxis.end(), T(0), [](T x, T current) { return x + pow(current, 2); });
		int n = xAxis.size();
		slope = (n*eXY - (sumX*sumY)) / (n*eX2 - pow(sumX, 2));
		y_intercept = (sumY - (slope*sumX)) / n;
	}

	template<class T> void DataTable<T>::display(std::ostream& os) const
	{
		os << std::setw(fieldW) << std::setprecision(dec) << "x"
			<< std::setw(fieldW) << std::setprecision(dec) << "y" << std::endl;
		for (int i = 0; i < xAxis.size(); ++i)
		{
			os << std::setw(fieldW) << std::fixed << std::setprecision(dec) << xAxis[i];
			os << std::setw(fieldW) << std::fixed << std::setprecision(dec) << yAxis[i];
			os << std::endl;
		}
	}
	template<class T> std::ostream& operator<<(std::ostream& os, const DataTable<T>& data)
	{
		data.display(os);
		return os;
	}

}
