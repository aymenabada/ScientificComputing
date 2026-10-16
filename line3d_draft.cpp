
/// Draft (!) base class for 3D line
class Line3D
{
 
  public:
 
 /// Constructor
 Line3D();
 
 /// Position vector as a function of the curve parameter
 /// sigma: r(sigma)
 std::vector<double> position(const double& sigma);
 
 /// Tangent vector as a function of the curve parameter
 /// sigma: dr/dsigma 
 std::vector<double> tangent(const double& sigma);
 
 /// Output n_point points along the curve,
 /// at equally spaced values of sigma between sigma=a and
 /// sigma=b. filename specifies the name of the file
 /// that will contain n_point lines, each containing
 /// (only!) the three coordinates (x, y, z) of the point.
 /// Coordinates are listed by themselves; no brackets or
 /// commas!
 void output(const std::string filename&, const double& a,
             double& b, const unsigned & n_point);
 
 /// Return the arclength along the curve between
 /// sigma=a and sigma=b. 
 double arclength(const double& a, const double& b);
 
  private:
 
 /// Add any additional private data or helper functions 
 /// that you may need to implement the functions
 /// defined above.

 [...]
 
 
};
