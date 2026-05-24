#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 1. Pythonが作ったCSVファイルを開く
    ifstream file("matrix.xls");
    if (!file.is_open()) {
        cerr << "ファイルが開けませんでした。" << std::endl;
        return 1;
    }

    // [アミノ酸の数 × 320次元] のデザイン行列 X を格納する2次元ベクトル
    vector<vector<float>> X;
    string line;

    // 2. ファイルを1行ずつ読み込む（1行 ＝ 1つのアミノ酸の320次元データ）
    while (getline(file, line)) {
        vector<float> row;
        stringstream ss(line);
        string value;

        // カンマ区切りで数字を分解して、row（1次元配列）に入れていく
        while (getline(ss, value, ',')) {
            row.push_back(stof(value)); // 文字列をfloatに変換
        }
        X.push_back(row); // 行列 X に追加
    }
    file.close();

    cout << "C++側へのデザイン行列 X の読み込みが成功しました！" << endl;
    cout << "アミノ酸の数 (行数): " << X.size() << endl;
    cout << "特徴量の次元数 (列数): " << X[0].size() << endl; // 320になります

    // ---------------------------------------------------------------
    // 3. ここから先が「あの緑の本」で学んだ数式（本質）の実装！
    // ---------------------------------------------------------------
    // ここで、行列 X を使って：
    // ・最小二乗法の行列計算（Xの転置 × X の逆行列 ...）を自作関数で解く
    // ・あるいは、重み w を勾配降下法の for ループで更新する
    // といった計算を、C++の圧倒的な超高速スピードで実行させます。

    return 0;
}
