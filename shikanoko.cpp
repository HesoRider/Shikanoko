/*
Copyright (C) 2025 ヘソライダー All Rights Reserved.
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

// しかのこでマルコフ連鎖
int next(int index)
{
    // 文字の順番で判断
    int next_index = 7;
    srand((unsigned)time(NULL));
    switch (index)
    {
    case 0: // し
        if (rand() % 2 == 0) next_index = 1; // か
        else next_index = 4; // た
        break;
    case 1: // か
        next_index = 2; // の
        break;
    case 2: // の
        next_index = 3; // こ
        break;
    case 3: // こ
        if (rand() % 3 == 0) next_index = 0; // し
        else if (rand() % 3 == 1) next_index = 2; // の
        else next_index = 4; // た
        break;
    case 4: // た
        next_index = 5; // ん
        break;
    case 5: // ん
        if (rand() % 2 == 0) next_index = 4; // た
        else next_index = 7; // おわり
        break;
    default:
        break;
    }

    return next_index;
}

int main()
{
    // 6つの文字から一つ選ぶ
    vector<string> shikanoko = {"し", "か", "の", "こ", "た", "ん"};

    // テキストファイルに結果を書き込み
    ofstream file("output.txt");
    if (!file)
    {
        cerr << "No File!" << endl;
        exit(1);
    }

    int index = 0;
    while (index < 7)
    {
        file << shikanoko[index];
        index = next(index);
    }
    file.close();
}