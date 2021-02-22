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
Compass latitudeDirection;
double longtitude;
Compass longitudeDirection;

GPS(double x, double a){
  if(((x>=0.0)&&(x<=90.0))&&((a>=0.0)&&(x<=180.0))){
    latitude= x;
    longtitude=a;
    latitudeDirection= Compass::N;
    longitudeDirection= Compass:: W;
  }
  else if(((x>0.0)||(x>90.0))&&((a>=0.0)&&(a<=180.0))){
    latitude=0;
    latitudeDirection= Compass::N;
    longtitude=a;
    longitudeDirection= Compass::W;
  }
  else if (((x<0.0)||(x>90.0))&&((a<0.0)||a>180.0))){
    latitude=0;
    latitudeDirection=Compass::N;
    longtitude=0;
    longtitudeDirection=Compass::W;
  }
}

GPS(){
  longtitude=0;
  latitude=0;
  latitudeDirection=Compass::N;
  longitudeDirection=Compass::W;
}
GPS(double x, Compass y, double a, Compass b){
  latitude=x;
  latitudeDirection=y;
  longtitude=a;
  longitudeDirection=b;

  if (((x>=0.0)&&(x<=90.0))&&((a>=0.0)&&(a<=180.0))){
    if (((y==Compass::N)||(y==Compass::S))&&((b==Compass::W)||(b==Compass::E))){
      latitudeDirection=y;
      longitudeDirection=b;
    }
    else if(((y!=Compass::N)&&(y!=Compass::S)&&(b!=Compass::W)||(b!=Compass::E))){
      latitude=x;
      longtitude=a;
    }
    else if (((x<0.0)||(x>90.0))&&((a>=0.0)&&(a<=180.0))){
      latitude=0;
      latitudeDirection=Compass::N;
      longtitude=a;
      longtitudeDirection=Compass::W;
    }
    else if (((x>=0.0)&&(x<=90.0))&&((a<0.0)||(a>180.0))){
      latitude=x;
      latitudeDirection=Compass::N;
      longtitude=0;
      longitudeDirection=Compass::W;
    }
    else if (((x<0.0)||(x>90.0))&&((a<0.0)||(a>180.0))){
      latitude=0;
      latitudeDirection=Compass::N;
      longitude=0;
      longitudeDirection=Compass::W;
    }
  }
  double getLatitudeDirection(){
    return latitudeDirection;
  }
  double getLongitudeDirection(){
    return longtitudeDirection;
  }
  double getLatitude(){
    return latitude;
  }
  double getLongitude(){
    return longtitude;
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
