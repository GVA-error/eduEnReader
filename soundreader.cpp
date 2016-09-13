#include "soundreader.h"

SoundReader::SoundReader()
{

}

qint64 SoundReader::getSample(qint64 sample)
{
    return rand() - RAND_MAX/2;
}
