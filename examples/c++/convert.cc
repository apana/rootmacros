//
// simple example to do decimal to string conversion
//

{
  //#include <sstream>
  //#include <stdexcept>


  Float_t z=1.;

  ostringstream ch_z;
  ch_z.flags ( ios_base::showpoint );
  ch_z.precision(2);
  ch_z << z ;

  string output=ch_z.str();

  cout << output << endl;

}
