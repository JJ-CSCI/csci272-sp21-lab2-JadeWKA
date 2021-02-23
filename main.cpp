//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};


// Write your code here
class GPS{
  private:

  double latitude;
  Compass latitudeDirection;
  double longitude;
  Compass longitudeDirection;

  public:

  GPS(): latitude{0.0}, 
  latitudeDirection{Compass::N},longitude{0.0},
  longitudeDirection{Compass::W}{}

  GPS(double lat, double lon)
  {latitude=lat;
  longitude=lon;
  latitudeDirection=Compass::N;
  longitudeDirection=Compass::W;
  
    if((0.0<=lat)&&(lat<=90.0)){
      latitude=lat;
    }
    else{
      latitude=0.0;
    }

    if((0.0<=lon)&&(lon<=180.0)){
      longitude=lon;
    }
    else{
      longitude=0.0;
    }
    latitudeDirection=Compass::N;
    longitudeDirection=Compass::W;
  
  };
  GPS(double lat, Compass latd, double lon, Compass lond)
  {
     if((0.0<=lat)&&(lat<=90.0)){
      latitude=lat;
    }
    else{
      latitude=0.0;
    }

    if((0.0<=lon)&&(lon<=180.0)){
      longitude=lon;
    }
    else{
      longitude=0.0;
    }
    
  if(latd==Compass::N || latd==Compass::S){
    latitudeDirection=latd;}
  else
  {latitudeDirection= latd;}
  if(lond==Compass::W || lond==Compass::E)
  {longitudeDirection=lond;}
  else
  {longitudeDirection= Compass::W;
  }
  };

  double getLatitude()
  {return latitude;}
  double getLongitude()
  {return longitude;}
  Compass getLatitudeDirection(){return latitudeDirection;}
  Compass getLongitudeDirection()
  {return longitudeDirection;}
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
