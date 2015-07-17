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

inline bool stringToList(list<string>& result, const char* src, const char* sep){
    result.clear();
    if (src == NULL || sep == NULL)
        return false;
    
    size_t seplen = strlen(sep);
    size_t seclen = strlen(src);
    const char *bg = src;
    const char *ed = src + seclen;
    do{
        const char* pos = strstr(bg, sep);
        if (pos != NULL)
        {
            if (pos != bg)
                result.push_back(string(bg, pos));
            bg = pos + seplen;
        }
        else{
            result.push_back(string(bg));
            break;
        }
    }while(bg < ed);
    return true;
}

#endif
