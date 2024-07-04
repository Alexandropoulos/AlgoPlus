#ifndef SHARPENING_FILTER_H
#define SHARPENING_FILTER_H

#ifdef __cplusplus
#include <iostream>
#include <vector>
#include "../image.h"
#endif

/**
* @brief sharpening_filter namespace 
*/
namespace sharpening_filter{
  /**
  * @brief apply_sharpening_filter function: applies a 3x3 laplacian filter to image img
  * @param img(Class Image): the input image
  * @return vector<vector<int32_t> > : the resulted image after applying the laplacian filter
  */
  std::vector<std::vector<int32_t> > apply_sharpening_filter(const std::vector<std::vector<int32_t> > &image){
    Image img(image);
    int height = img._height();
    int width = img._width();
    Image resulted_img(height, width);
    std::vector<std::vector<int32_t> > kernel = {{0, 1, 0}, {1, -4, 1}, {0, 1, 0}};
    return img.apply_filter2d(kernel).get_2d_array();
  }
}


#endif
