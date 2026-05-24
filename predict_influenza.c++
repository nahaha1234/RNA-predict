#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <random>
#define NUM_Variety 50
#define NUM_amino 320

using namespace std;

struct TreeNode{
    int feature_id;
    double threshold;
    int left_class_id;
    int right_class_id;
};

void LoadSolubilityFile(vector<string>&amino_name,
    vector<double>&amino_answer,vector<vector<double>>&amino_chara){
    string natural_data = "/workspaces/RNA-predict/influenza_ha_dataset.xls";
    string predict_data = "/workspaces/RNA-predict/virus_X.xls";

    ifstream its(natural_data);
    if(!its){
        cerr << "cannot open!";
        exit(1);
    }

    string garabege;
    for(int i = 0; i < NUM_Variety+1; i++){
        for(int j = 0; j < 3; j++){
            if(i == 0) its >> garabege;
            else{
                if(j==0) its >> amino_name[i];
                else if(j==1) its >> garabege;
                else its >> amino_answer[i];
            }
        }
    }

    ifstream ifs(predict_data);
    if(!ifs){
        cerr << "cannot open!";
        exit(1);
    }

    for(int i = 0; i < NUM_Variety+1; i++){
        for(int j = 0; j < NUM_amino+1;j++){
            ifs >> amino_chara[i][j];
        }
    }
}

int main(void){
    vector<string> amino_name(NUM_Variety," ");
    vector<double> amino_answer(NUM_Variety, 0);
    vector<vector<double>> amino_chara(NUM_Variety,vector<double> (NUM_amino,0));
    LoadSolubilityFile(amino_name,amino_answer,amino_chara);
    cout << amino_name[1] << " " << amino_chara[1][1];
}