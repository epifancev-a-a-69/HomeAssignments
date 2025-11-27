/*
Epifancev Artem
st142163@student.spbu.ru
assignment 2b
*/

#include <iostream>
#include <string>
#include <sstream>

int main(){
    double* stack = new double[100];
    double* j = stack; 

    std::cout<<"Введите обратную польскую запись\n";
    std::string word; 
    std::string rec;
    std::getline(std::cin, rec);
    std::stringstream stream(rec);

    while (stream>>word){
      if (word=="*"){
                double a = *j;
                j--;
                double b = *j;
                *j = a*b;
      } else if (word=="+"){
                double a = *j;
                j--;
                double b = *j;
                *j = a+b;
      } else if (word=="-"){
                double a = *j;
                j--;
                double b = *j;
                *j = b-a;
      } else if (word=="/"){
                double a = *j;
                j--;
                double b = *j;
                *j = b/a;
      } else {
            j++;
            int num = stol(word);
            *j = num;
      }
    }
    std::cout<<*j<<"\n";
    delete[] stack;
}
