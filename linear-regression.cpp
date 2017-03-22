#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

struct Data{
    int features[384];
    int id;
};
// struct Param{
//     vector<double> w;
//     double d;
//     Param(vector<double> w1, double d1) :w(w1), d(d1){};
//     Param() :w(vector<double>()), d(0.0){}
// };

// class Logistic{
// public:
//     Logistic(){

//         //载入traindata文件构造dataSet;
//         loadDataSet(dataSet);
//         //初始化Param，w的长度与数据特征的长度相同，初值为0.0。d的初值也为0.0
//         vector<double> pw(dataSet[0].features.size(), 0.0);
//         Param pt(pw, 0.0);
//         param = pt;
//     };
void loadDataSet(vector<Data>& ds, string dataFile);
int main() {
	//load the data and initial
	//will get the two-dimension array for the training set and one array for ref
	//two-dimension array for test
    vector<Data> trainData;
	loadDataSet();
    //

}
    void loadDataSet(vector<Data>& ds, string dataFile = "./save_train.txt"){
        ifstream fin(dataFile.c_str());
        if (!fin){
            cout << "文件打开失败" << endl;
            exit(0);
        }
        while (fin){
            string line;
            getline(fin, line);
            if (line.size()>3){
                stringstream sin(line);
                int t;
                sin >> t;
                vector<int> fea;
                while (sin){
                    char c = sin.peek();
                    if (int(c) != -1){
                        sin >> t;
                        fea.push_back(t);
                    }
                }
                int cl = fea.back();
                fea.pop_back();
                ds.push_back(Data(fea, cl));
            }
        }
    }