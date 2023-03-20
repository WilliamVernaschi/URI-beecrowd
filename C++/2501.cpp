#include <iostream>
#include <vector>
// Hamming like sequences Generator
//
// Nigel Galloway. August 13th., 2012
//
typedef long long ll;
class Ham {
private:
    std::vector<unsigned long long> _H, _hp, _hv, _x;
public:
    bool operator!=(const Ham& other) const {return true;}
    Ham begin() const {return *this;}
        Ham end() const {return *this;}
    unsigned long long operator*() const {return _x.back();}
    Ham(const std::vector<unsigned long long> &pfs):_H(pfs),_hp(pfs.size(),0),_hv({pfs}),_x
    const Ham& operator++() {
      for (long long i=0; i<_H.size(); i++) for (;_hv[i]<=_x.back();_hv[i]=_x[++_hp[i]]*_H[
      _x.push_back(_hv[0]);
      for (long long i=1; i<_H.size(); i++) if (_hv[i]<_x.back()) _x.back()=_hv[i];
      return *this;
    }
};
int main() {
  int n, m;
  while(std::cin >> n >> m){
    if(!(n+m)) break;
    std::vector<unsigned long long> x;
    for(int i = 0; i < n; i++){
      long long p; std::cin >> p;
      x.push_back(p);
    }
    long long count = 0;
    for (unsigned long long i : Ham(x)) {
      if (count++ == m){
        std::cout << i << std::endl;
        break;
      }
    }
  }
  return 0;
}
