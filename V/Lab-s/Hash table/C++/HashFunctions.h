#include <string>

using namespace std;

class HashFunctions
{
public:
    /// @brief Popular hash function - MurMur3
    /// @param key Key, that need to be hashed
    /// @param seed Seed of hashing alghoritm 
    /// @return Hash for inputted key
    static int murmur3(string key, int seed = 0)
    {
        int remainder = key.length() & 3;
        int bytes = key.length() - remainder;
        int h1 = seed;
        int c1 = 0xcc9e2d51;
        int c2 = 0x1b873593;
        int i = 0;

        while (i < bytes)
        {
            int k1 =
                ((key[i] & 0xff)) |
                ((key[++i] & 0xff) << 8) |
                ((key[++i] & 0xff) << 16) |
                ((key[++i] & 0xff) << 24);
            ++i;

            k1 = ((((k1 & 0xffff) * c1) + (((((int)(k1 >> 16)) * c1) & 0xffff) << 16))) & 0xffffffff;
            k1 = (k1 << 15) | ((int)(k1 >> 17));
            k1 = ((((k1 & 0xffff) * c2) + ((((int)(k1 >> 16) * c2) & 0xffff) << 16))) & 0xffffffff;

            h1 ^= k1;
            h1 = (h1 << 13) | ((int)(h1 >> 19));
            int h1b = ((((h1 & 0xffff) * 5) + ((((int)(h1 >> 16) * 5) & 0xffff) << 16))) & 0xffffffff;
            h1 = (((h1b & 0xffff) + 0x6b64) + ((((int)(h1b >> 16) + 0xe654) & 0xffff) << 16));
        }

        int k1 = 0;

        switch (remainder)
        {
        case 3:
            k1 ^= (key[i + 2] & 0xff) << 16;
        case 2:
            k1 ^= (key[i + 1] & 0xff) << 8;
        case 1:
            k1 ^= (key[i] & 0xff);

            k1 = (((k1 & 0xffff) * c1) + ((((int)(k1 >> 16) * c1) & 0xffff) << 16)) & 0xffffffff;
            k1 = (k1 << 15) | (int)(k1 >> 17);
            k1 = (((k1 & 0xffff) * c2) + ((((int)(k1 >> 16) * c2) & 0xffff) << 16)) & 0xffffffff;
            h1 ^= k1;
        }

        h1 ^= key.length();

        h1 ^= (int)(h1 >> 16);
        h1 = (((h1 & 0xffff) * 0x85ebca6b) + ((((int)(h1 >> 16) * 0x85ebca6b) & 0xffff) << 16)) & 0xffffffff;
        h1 ^= (int)(h1 >> 13);
        h1 = ((((h1 & 0xffff) * 0xc2b2ae35) + ((((int)(h1 >> 16) * 0xc2b2ae35) & 0xffff) << 16))) & 0xffffffff;
        h1 ^= (int)(h1 >> 16);

        return (int)(h1 >> 0);
    }
};
