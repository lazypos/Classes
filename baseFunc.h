//
//  baseFunc.h
//  redten
//
//  Created by zcw on 15-6-2.
//
//

#ifndef redten_baseFunc_h
#define redten_baseFunc_h

#include <map>
#include <string>
using namespace std;

void DoSeparate(const string& mData, const string& mSepStr, map<string, string>& _string_map)
{
    if (mData.empty() || mSepStr.empty())
        return;
    
    _string_map.clear();
    size_t len = mSepStr.length();
    char* src = (char *)mData.c_str();
    char* sp = (char *)mSepStr.c_str();
    
    char* pitem = strstr(src, sp);
    char* eq = NULL;
    while(pitem != NULL){
        eq = strstr(src, "=");
        if (eq && pitem > eq)
            _string_map.insert(make_pair(string(src, eq), string(eq+1, pitem-eq-1)));
        
        src = pitem+len;
        pitem = strstr(src, sp);
    }
}

#endif
