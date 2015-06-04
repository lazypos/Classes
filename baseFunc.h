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

inline void DoSeparate(const string& mData, const string& mSepStr, map<string, string>& _string_map)
{
    if (mData.empty() || mSepStr.empty())
        return;
    
    _string_map.clear();
    size_t len = mSepStr.length();
    size_t srclen = mData.length();
    char* src = (char *)mData.c_str();
    char* src_end = src + srclen;
    char* sp = (char *)mSepStr.c_str();
    
    char* pitem = strstr(src, sp);
    char* eq = NULL;
    while(src < src_end){
        eq = strstr(src, "=");
        if (eq && (pitem > eq || pitem == NULL ))
            _string_map.insert(make_pair(string(src, eq), string(eq+1, pitem-eq-1)));
        
        src = pitem+len;
        pitem = strstr(src, sp);
        if (pitem == NULL)
            pitem = src_end;
    }
}

#endif
