#include<string>
std::string task(std::string s, unsigned n){
  bool have_star=false;
  for(unsigned i = 0;i<n;i++){

    if(have_star){
      s[i] = '-';
    }

    if(s[i]=='*'){
      have_star = true;
    }
      
  }
  return s;
}