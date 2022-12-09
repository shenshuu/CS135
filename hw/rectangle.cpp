// Implement a class Rectangle. Provide a constructor to 
// construct a rectangle with a given width and height, 
// member functions get_perimeter and get_area that compute the perimeter and area, 
// and a member function void resize(double factor) 
// that resizes the rectangle by multiplying the width and height by the given factor.

class Rectangle {
    private:
        double height;
        double width;

    public:

        Rectangle(double h, double w):
            height(h), width(w) {}
            
        double get_perimeter() {
            return width * 2.0 + height * 2.0;
        }

        double get_area() {
            return height * width;
        }

        void resize(double factor) {
            height *= factor;
            width *= factor;
        }
};