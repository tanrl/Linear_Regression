#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdlib>

#define SAMPLE "./sample_submission.csv"
#define TRAIN "./save_train.csv"
#define TEST "./save_test.csv"

using namespace std;

 struct Data {
    vector<float> features;
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
void loadDataSet(vector<Data> & ds,const char * dataFile);
int main() {
    string line;
	//load the data and initial
	//will get the two-dimension array for the training set and one array for ref
	//two-dimension array for test
    vector<Data> trainData;
<<<<<<< HEAD
	loadDataSet(trainData, TRAIN);
    return 0;
=======
	loadDataSet();
    //
    hello();
>>>>>>> cbd0b9d0f754328158d35282c0df9e9463342f51
}
void loadDataSet(vector<Data> & ds,const char * dataFile) {
    int id;
    vector<float> fea;
    float temp;
    Data d;
    string line;
    ifstream fin(dataFile);
    if (!fin){
        cout << "文件打开失败" << endl;
        exit(0);
    }
    getline(fin, line);
    getline(fin, line);
    while (!fin.eof()){
        stringstream sin(line);
        sin >> id;
        while (sin){
            sin >> temp;
            fea.push_back(temp);
        }
        d.features = fea;
        d.id = id;
        ds.push_back(d);
        sin.str("");
        sin.clear();
        getline(fin, line);
    }
    fin.close();
}