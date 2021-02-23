//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};


// Write your code here
class GPS {
  private:
  double latitude;
  double longtitude;
  double lowlat = 0.0;
  double hilat= 90.0;
  double lowlong= 0.0;
  double hilong= 180.0;
  Compass latitudeDirection;
  Compass longitudeDirection;

  public:

  GPS(double a, double b){
    if(((lowlat<=a<=hilat))&&(lowlong<=b<=hilong)){
      latitude=0.0;
      longtitude=0.0;
      latitudeDirection=Compass::N;
      longitudeDirection=Compass::W;
    }
    else if (((lowlat>a)||(a>hilat))&&((lowlong<=b<=hilong))){
      latitude=0.0;
      longtitude=b;
      latitudeDirection=Compass::N;
      longitudeDirection=Compass::W;
    }
    else if(((lowlat<=a<=hilat))&&((lowlong>b)||(hilong<b))){
      latitude=a;
      longtitude=0.0;
      latitudeDirection=Compass::N;
      longitudeDirection=Compass::W;
    }
    else if(((lowlat>a)||(a>hilat))&&((lowlong>b)||(hilong<b))){
      latitude=0.0;
      longtitude=0.0;
      latitudeDirection=Compass::N;
      longitudeDirection=Compass::W;
    }
    }

    GPS(double x, Compass o, double y, Compass k){
      latitude=x,
      longtitude=y;
      latitudeDirection=o;
      longitudeDirection=k;

      if(((lowlat<=x<=hilat))&&(lowlong<=y<=hilong)){
      if((o==Compass::N||o==Compass::S)&&(k==Compass::W||k==Compass::E)){
        latitudeDirection=o;
        longitudeDirection=k;
      }
      else if((o!=Compass::N||o!=Compass::S)&&(k==Compass::W||k==Compass::E)){
        latitudeDirection=Compass::N;
        longitudeDirection=k;
      }
      else if((o==Compass::N||o==Compass::S)&&(k!=Compass::W||k!=Compass::E)){
        latitudeDirection=o;
        longitudeDirection=Compass::W;
      }
      latitude=x;
      longtitude=y;
    }

    }
  double getLatitude(){
    return latitude;
  }
  double getLongitude(){
    return longtitude;
  }
  Compass getLatitudeDirection(){
    return latitudeDirection;
  }
  Compass getLongitudeDirection(){
    return longitudeDirection;
  }

  GPS(){
    latitude=0.0;
    longtitude=0.0;
    latitudeDirection=Compass::N;
    longitudeDirection=Compass::W;
  }
  
};
//------------------------------
//   DO NOT MODIFY TEST CASES
//------------------------------

TEST_CASE( "GPS" ) {
    SECTION( "t1" ) {
        GPS c;
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t2" ) {
        GPS c{12.12, 50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t3" ) {
        GPS c{12.12, Compass::S, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::S );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t4" ) {
        GPS c{122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t5" ) {
        GPS c{122.12, 500.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t6" ) {
        GPS c{-122.12, 50.34};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLongitude() == 50.34 );
    }
    SECTION( "t7" ) {
        GPS c{12.12, -50.34};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLongitude() == 0.0 );
    }
    SECTION( "t8" ) {
        GPS c{12.12, Compass::W, 50.34, Compass::E};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::E );
    }
    SECTION( "t9" ) {
        GPS c{12.12, Compass::N, 50.34, Compass::N};
        REQUIRE( c.getLatitude() == 12.12 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 50.34 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
    SECTION( "t10" ) {
        GPS c{-12.12, Compass::E, 540.34, Compass::N};
        REQUIRE( c.getLatitude() == 0.0 );
        REQUIRE( c.getLatitudeDirection() == Compass::N );
        REQUIRE( c.getLongitude() == 0.0 );
        REQUIRE( c.getLongitudeDirection() == Compass::W );
    }
}
//------------------------------
