#include <cxxtest/TestSuite.h>

#include "julian.h"
#include "gregorian.h"
using namespace lab2;

class MyTestSuite : public CxxTest::TestSuite 
{
public:
  void test_year( void )
  {
    Gregorian g;
    TS_ASSERT_EQUALS(g.mod_julian_day(), 55110);
    TS_ASSERT_EQUALS(g.year(), 2009);
    TS_ASSERT_EQUALS(g.month(), 10);
    TS_ASSERT_EQUALS(g.day(), 6);
    TS_ASSERT_EQUALS(g.mod_julian_day(), 55110);
    // lägg till eller skapa ny med offset 10000
    // ska bli 23e march 1886
    Gregorian p(10000);
    TS_ASSERT_EQUALS(p.year(), 1886);
    TS_ASSERT_EQUALS(p.month(), 4);
    TS_ASSERT_EQUALS(p.day(), 4);
    TS_ASSERT_EQUALS(p.mod_julian_day(), 10000);
    // 100000 = 31a augusti 2132

    Gregorian l(100000);
    TS_ASSERT_EQUALS(l.year(), 2132);
    TS_ASSERT_EQUALS(l.month(), 9);
    TS_ASSERT_EQUALS(l.day(), 1);
    TS_ASSERT_EQUALS(l.mod_julian_day(), 100000);
 
    Gregorian q(0);
    TS_ASSERT_EQUALS(q.year(), 1858);
    TS_ASSERT_EQUALS(q.month(), 11);
    TS_ASSERT_EQUALS(q.day(), 17);
    TS_ASSERT_EQUALS(q.mod_julian_day(), 0);
  }

  void test_constructors( void ) {
    Gregorian j(1858, 11, 17);
    TS_ASSERT_EQUALS(j.year(), 1858);
    TS_ASSERT_EQUALS(j.month(), 11);
    TS_ASSERT_EQUALS(j.day(), 17);
    TS_ASSERT_EQUALS(j.mod_julian_day(), 0);
  }
  void test_constructors2( void ) {
    Gregorian j(2009, 10, 5);
    TS_ASSERT_EQUALS(j.year(), 2009);
    TS_ASSERT_EQUALS(j.month(), 10);
    TS_ASSERT_EQUALS(j.day(), 5);
    TS_ASSERT_EQUALS(j.mod_julian_day(), 55109);
  }
  void test_constructors3( void ) {
    Gregorian j(1890, 2, 13);
    TS_ASSERT_EQUALS(j.year(), 1890);
    TS_ASSERT_EQUALS(j.month(), 2);
    TS_ASSERT_EQUALS(j.day(), 13);
    TS_ASSERT_EQUALS(j.mod_julian_day(), 11411);
  }



  void test_mod_julian_day( void ) {
    Gregorian g;
    TS_ASSERT_EQUALS(Gregorian::mod_julian_day(1858,11,17), 0);
    TS_ASSERT_EQUALS(Gregorian::mod_julian_day(1900, 1, 1), 15020);


    TS_ASSERT_EQUALS(Gregorian::mod_julian_day(2009, 10, 5), 55109);
    TS_ASSERT_EQUALS(Gregorian::mod_julian_day(1973, 3, 11), 41752);
}

  void test_day( void ) {
    Gregorian g;
    g.offset = 0;
    TS_ASSERT_EQUALS(g.day(), 17);
    TS_ASSERT_EQUALS(g.month(), 11);
    g.offset = 20;
    TS_ASSERT_EQUALS(g.day(), 7);
    TS_ASSERT_EQUALS(g.month(), 12);
    g.offset = 10;
    TS_ASSERT_EQUALS(g.day(), 27);
    TS_ASSERT_EQUALS(g.month(), 11);
    g.offset = 55109;
    TS_ASSERT_EQUALS(g.day(), 5);
}

  void test_add_month(){
    Gregorian g(2009,10,6);
    g.add_month(1);
    TS_ASSERT_EQUALS(g.month(), 11);
    TS_ASSERT_EQUALS(g.day(), 6);

    Gregorian g2(2008,1,29);
    g2.add_month(1);
    TS_ASSERT_EQUALS(g2.month(), 2);
    TS_ASSERT_EQUALS(g2.day(), 29);
    
    Gregorian g3(2007,1,29);
    g3.add_month(1);
    TS_ASSERT_EQUALS(g3.month(), 2);
    TS_ASSERT_EQUALS(g3.day(), 28);
    
    Gregorian g4(2008,1,29);
    g4.add_month(10);
    TS_ASSERT_EQUALS(g4.month(), 11);
    TS_ASSERT_EQUALS(g4.day(), 29);
    
    Gregorian g5(2008,3,31);
    g5.add_month(5);
    TS_ASSERT_EQUALS(g5.month(), 8);
    TS_ASSERT_EQUALS(g5.day(), 30);
  }

  void test_sub_month(){
    Gregorian g(2009,10,6);
    g.add_month(-1);
    // tar bort 31 dagar
    TS_ASSERT_EQUALS(g.month(), 9);
    TS_ASSERT_EQUALS(g.day(), 6);

    Gregorian g2(2008,1,29);
    g2.add_month(-1);
    TS_ASSERT_EQUALS(g2.month(), 12);
    TS_ASSERT_EQUALS(g2.day(), 29);
    
    Gregorian g3(2007,1,29);
    g3.add_month(-1);
    TS_ASSERT_EQUALS(g3.month(), 12);
    TS_ASSERT_EQUALS(g3.day(), 29);

    Gregorian g4(2007,3,29);
    g4.add_month(-1);
    TS_ASSERT_EQUALS(g4.month(), 2);
    TS_ASSERT_EQUALS(g4.day(), 27);
  }

  void test_add_year(){
    Gregorian g4(2007,3,29);
    g4.add_year(1);
    TS_ASSERT_EQUALS(g4.year(), 2008);
    TS_ASSERT_EQUALS(g4.month(), 3);
    TS_ASSERT_EQUALS(g4.day(), 29);
    Gregorian g5(2007,3,29);
    g5.add_year(-1);
    TS_ASSERT_EQUALS(g5.year(), 2006);
    TS_ASSERT_EQUALS(g5.month(), 3);
    TS_ASSERT_EQUALS(g5.day(), 29);
    Gregorian g6(2008,2,29);
    g6.add_year(-108);
    TS_ASSERT_EQUALS(g6.year(), 1900);
    TS_ASSERT_EQUALS(g6.month(), 2);
    TS_ASSERT_EQUALS(g6.day(), 28);
    Gregorian g7(2008,2,29);
    g7.add_year(107);
    TS_ASSERT_EQUALS(g7.year(), 2115);
    TS_ASSERT_EQUALS(g7.month(), 2);
    TS_ASSERT_EQUALS(g7.day(), 28);
    Gregorian g8(2008,2,29);
    g8.add_year(80);
    TS_ASSERT_EQUALS(g8.year(), 2088);
    TS_ASSERT_EQUALS(g8.month(), 2);
    TS_ASSERT_EQUALS(g8.day(), 29);

  }

  void test_exceptions(){

  }
  
  void test_week_day(){
    Gregorian g1(1858,11,17);
    TS_ASSERT_EQUALS(g1.week_day(), 3);

    Gregorian g(2009,10,6);
    TS_ASSERT_EQUALS(g.week_day(), 2);
  }

  void test_names(){
    Gregorian g(2009,10,6);
    TS_ASSERT_EQUALS(g.month_name(), "october");
    TS_ASSERT_EQUALS(g.week_day_name(), "tuesday");

  }

  void test_comp(){
    Gregorian g(2009,10,6);
    Gregorian g2(2009,10,6);
    Gregorian g3(2009,10,7);
    TS_ASSERT_EQUALS(g<g2,false);
    TS_ASSERT_EQUALS(g==g2,true);
    TS_ASSERT_EQUALS(g>g2,false);
    TS_ASSERT_EQUALS(g<=g2,true);
    TS_ASSERT_EQUALS(g>=g2,true);

    TS_ASSERT_EQUALS(g<g,false);
    TS_ASSERT_EQUALS(g==g,true);
    TS_ASSERT_EQUALS(g>g,false);
    TS_ASSERT_EQUALS(g<=g,true);
    TS_ASSERT_EQUALS(g>=g,true);
  
    TS_ASSERT_EQUALS(g<g3,true);
    TS_ASSERT_EQUALS(g==g2,true);
    TS_ASSERT_EQUALS(g>g2,false);
    TS_ASSERT_EQUALS(g<=g2,true);
    TS_ASSERT_EQUALS(g>=g2,true);  
  }

  void test_inc(){
    Gregorian g(2009,10,7);
    g++;
    TS_ASSERT_EQUALS(g.day(),8);
    Gregorian g1(2009,10,7);
    ++g1;
    TS_ASSERT_EQUALS(g1.day(),8);
    
  }
}; //den bästa sommaren
