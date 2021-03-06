
#include "Tcp2.h"
#include "Binary.h"

H_BNAMSP

SINGLETON_INIT(CTcp2)
CTcp2 objTcp2;

CTcp2::CTcp2(void)
{
    setName("tcp2");
}

CTcp2::~CTcp2(void)
{
}

int CTcp2::parsePack(struct H_Session *, char *pAllBuf, const size_t &iLens, class CBinary *pBinary)
{
    unsigned short uiBufLens(H_INIT_NUMBER);
    size_t iHeadLens(sizeof(uiBufLens));
    if (iHeadLens > iLens)
    {
        return H_INIT_NUMBER;
    }

    uiBufLens = ntohs(*(unsigned short*)(pAllBuf));
    if (H_INIT_NUMBER == uiBufLens)
    {
        return (int)iHeadLens;
    }
    if (uiBufLens + iHeadLens > iLens)
    {
        return H_INIT_NUMBER;
    }

    pBinary->setReadBuffer(pAllBuf + iHeadLens, uiBufLens);

    return (int)(uiBufLens + iHeadLens);
}

H_ENAMSP
