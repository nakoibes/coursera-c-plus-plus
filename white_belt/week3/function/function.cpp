//
// Created by nakoibes on 13.08.2021.
//

//
// Created by nakoibes on 11.08.2021.
//
#include<iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <map>

using namespace std;

//struct Image {
//    double quality;
//    double freshness;
//    double rating;
//};
//
//struct Params {
//    double a;
//    double b;
//    double c;
//};

class Part {
public:
    Part(const char &new_operation, const double &new_value) {
        operation = new_operation;
        value = new_value;
    }

    double Apply(double &val) const{
        if (operation == '+') {
            return val + value;
        }
        else if (operation == '-'){
            return val - value;
        }
        else if (operation == '/'){
            return val / value;
        }
        else{
            return val * value;
        }
    }
    void Invert(){
        if (operation == '+')
        {
            operation = '-';
        }
        else if (operation == '-'){
            operation = '+';
        }
        else if (operation == '/'){
            operation = '*';
        }
        else if (operation == '*'){
            operation = '/';
        }
    }

public:
    char operation;
    double value;

};

class Function {
public:
    void AddPart(const char &c, const double &part) {
        parts.push_back({c, part});
    }
    double Apply(double val) const{
        for (const auto& part:parts)
        {
            val = part.Apply(val);
        }
        return val;
    }
    void Invert(){
        for (auto& part:parts)
        {
            part.Invert();

        }
        reverse(parts.begin(),parts.end());
    }

private:
    vector<Part> parts;
};

//Function MakeWeightFunction(const Params& params,
//                            const Image& image) {
//    Function function;
//    function.AddPart('*', params.a);
//    function.AddPart('-', image.freshness * params.b);
//    function.AddPart('+', image.rating * params.c);
//    return function;
//}
//
//double ComputeImageWeight(const Params& params, const Image& image) {
//    Function function = MakeWeightFunction(params, image);
//    return function.Apply(image.quality);
//}
//
//double ComputeQualityByWeight(const Params& params,
//                              const Image& image,
//                              double weight) {
//    Function function = MakeWeightFunction(params, image);
//    function.Invert();
//    return function.Apply(weight);
//}
//
//int main() {
//    Image image = {10, 2, 6};
//    Params params = {4, 2, 6};
//    cout << ComputeImageWeight(params, image) << endl;
//    cout << ComputeQualityByWeight(params, image, 52) << endl;
//    return 0;
//}
