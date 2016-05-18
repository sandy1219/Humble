
#ifndef H_HTTPD_H_
#define H_HTTPD_H_

#include "NetParser.h"
#include "Singleton.h"

H_BNAMSP

class CHttp : public CParser, public CSingleton<CHttp>
{
public:
    CHttp(void);
    ~CHttp(void);

    size_t parsePack(struct H_Session *, char *pAllBuf, const size_t &iLens, class CBinary *pBinary);
    void creatPack(std::string *pOutBuf, const char *pszMsg, const size_t &iLens);

private:
    H_DISALLOWCOPY(CHttp);
    size_t getHeadLens(const char *pBuffer);
    bool getChunkLens(const char *pBuffer, size_t &iChunkLens);
    bool getContentLens(const char *pszHead, const size_t &iHeadLens, size_t &iContentLens);
    bool checkChunk(const char *pszHead, const size_t &iHeadLens);

private:
    size_t m_iHeadEndFlagLens;
    size_t m_iChunkEndFlagLens;
};

H_ENAMSP

#endif //H_HTTPD_H_
