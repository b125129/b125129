#include <iostream>
using namespace std;

class Compressor {
public:
    //virtual void compress=0();
    virtual void compress(double fileSize) {
        cout << "Base compressor." << endl;
    }
};

class TextCompressor : public Compressor {
public:
    void compress(double fileSize) override {
        double compressedSize = fileSize * 0.40;
        cout << "[Text Compressor] Original Size: " << fileSize 
             << " MB, Compressed Size: " << compressedSize << " MB" << endl;
    }
};

class ImageCompressor : public Compressor {
public:
    void compress(double fileSize) override {
        double compressedSize = fileSize * 0.70;
        cout << "[Image Compressor] Original Size: " << fileSize 
             << " MB, Compressed Size: " << compressedSize << " MB" << endl;
    }
};

int main() {
    TextCompressor textComp;
    ImageCompressor imgComp;
    
    textComp.compress(100.0);
    imgComp.compress(100.0);
    
    return 0;
}