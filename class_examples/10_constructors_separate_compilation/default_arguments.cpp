/*
 * Name        : default_arguments.cpp
 * Author      : Luke Sathrum
 * Description : Showing how to use default arguments
 */

#include <iostream>
using std::cout;
using std::endl;

/*
 * This class represents a cube.
 */
class Cube {
 public:
  /*
   * This function will set the member variables to the given
   * passed in values. Note that width and height have default values
   */
  void SetVolume(int length, int width = 1, int height = 1);
  /*
   * This function will output our member varaibles using cout
   */
  void Output();
 private:
  // Member Names
  int length_;
  int width_;
  int height_;
};

// Program starts here
int main() {
  // Create some objects from the class
  Cube one, two, three;

  // Call our Set member function using default arguments
  one.SetVolume(4, 3, 2);
  two.SetVolume(4, 3);
  three.SetVolume(4);

  // This won't work as we don't have a default argument for length
//  one.SetVolume();

  // Call our output() member functions
  one.Output();
  two.Output();
  three.Output();

  // This ends our program
  return 0;
}

// Notice we DO NOT put default arguments here
void Cube::SetVolume(int length, int width, int height) {
  length_ = length;
  width_ = width;
  height_ = height;
}

void Cube::Output() {
  cout << "Length: " << length_ << endl
       << "Width : " << width_ << endl
       << "Height: " << height_ << endl << endl;
}
