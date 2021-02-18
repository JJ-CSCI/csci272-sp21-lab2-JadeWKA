//------------------------------
//  DO NOT MODIFY NEXT LINE
//------------------------------
#include "catch.hpp"
//------------------------------

// Use this enum class for indicating the lat/long direction
enum class Compass {N, S, W, E};
double latitude {0.0};
double longtitude {0.0};
Compass latitudeDirection;
Compass longtitudeDirection;

double getLatitude () {
    return latitude; }
double getLongtitude () {
    return longtitude; }
Compass getLatitudeDirection () {
    return latitudeDirection; }
Compass getLongtitudeDirection () {
    return longtitudeDirection; }
// Write your code here

class GPS {
  double latitude;
  if(latitude<0.0 || latitude>90.0){
    latitude=latitude.bad;
  }
  else if(latitude>=0.0 && latitude<=90.0){
    return latitude;
  }
  enum class latitudeDirection{N,S};
  enum class longtitudeDirection{W,E};
  double longtitude;
  if(longtitude<0.0 || longtitude>180.0){
    longtitude=longtitude.bad;
  }
  else if(longtitude>=0.0 && longtitude<=180.0){
    return longtitude;
  }
   if(latitude==0.0&&longtitude==0.0){
     return Compass::N;
     return Compass::W;
  }
  else if (latitude==new latitude&&longtitude== new longtitude){
     return Compass::N;
     return Compass::W;
  }
  else{
     return Compass::S;
     return Compass::E;
  }
  if(latitude<0.0 || latitude>90.0){
    return latitude=0.0;
    return Compass::N;
  }
  if(longtitude<0.0 || latitude>180.0){
    return latitude=0.0;
   return Compass::W;}

  

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
