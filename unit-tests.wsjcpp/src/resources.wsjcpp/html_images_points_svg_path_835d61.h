#include <wsjcpp_core.h>

class RES_html_images_points_svg : public WsjcppResourceFile { 
    public:
        virtual const std::string &getFilename() const override;
        virtual const std::string &getPackAs() const override;
        virtual int getBufferSize() const override;
        virtual const char *getBuffer() const override;
};