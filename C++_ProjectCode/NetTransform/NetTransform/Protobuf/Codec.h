#pragma once
#include <string>

/*��������						**/
class Codec_Base
{
public:
	Codec_Base();
    virtual ~Codec_Base();

public:
    virtual std::string encodeMsg();
    virtual void*       decodeMsg();

};