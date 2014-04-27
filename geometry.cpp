//solution by Wsl_F
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <algorithm>
#define author Wsl_F
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <x86intrin.h>

using namespace std;

typedef long long LL;
typedef double dbl;
typedef vector<int> vi;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)


#define sqr(x) ((x)*(x))
 const double eps= 1e-10;
 typedef double real;


template <typename tPoint> class Point;
template <typename tPoint> class Vector;

template <typename tPoint> class Segment;
template <typename tPoint, typename tParam> class LineABC;
template <typename tPoint> class Ray;

template <typename tPoint> class Triangle;
template <typename tPoint> class Polygon;

template <typename tPoint, typename tR> class Circle;




 real det (real a, real b, real c, real d)
 {
	return a * d - b * c;
 }


template <typename tPoint, typename tR>
class Circle
{
  private:
      Point<tPoint> O;
      tR R;

  public:
      Circle() : O(0,0), R(0)       {  }
      Circle(Point<tPoint> p, tR r) {O= p; R= r;}
      Circle(Point<tPoint> A, Point<tPoint> B, Point<tPoint> C)
      {
            Point<tPoint> o; tR r;
            calculateCenterRadius(A,B,C,o,r);
            O= o; R= r;
      }

      Point<tPoint> getO()                  { return O; }
      void setO(Point<tPoint> p)            { O= p;     }

      tR getR()                             { return R; }
      void setR(tR r)                       { R= r;     }

      void setOR(Point<tPoint> p, tR r)     { O= p; R=r; }

      static void calculateCenterRadius(Point<tPoint> A, Point<tPoint> B, Point<tPoint> C, Point<tPoint> & o, tR & r)
      {
        #define x1 A.getX()
        #define x2 B.getX()
        #define x3 C.getX()

        #define y1 A.getY()
        #define y2 B.getY()
        #define y3 C.getY()
          {//if 3 Points on 1 line
           Vector<tPoint> AB(x2-x1,y2-y1);
           Vector<tPoint> AC(x3-x1,y3-y1);
           if (AB.collinear(AC))
           {
               o.setXY(0,0); r= 0;
               return;
           }
          }

            tPoint a1,b1,c1,a2,b2,c2;
            a1= 2*(x2-x1); b1= 2*(y2-y1); c1= sqr(x1)+sqr(y1)-sqr(x2)-sqr(y2);
            a2= 2*(x3-x2); b2= 2*(y3-y2); c2= sqr(x2)+sqr(y2)-sqr(x3)-sqr(y3);

            //cout<<a1<<"  "<<b1<<"  "<<c1<<endl;
            //cout<<a2<<"  "<<b2<<"  "<<c2<<endl;

            tPoint x,y;
            if (a1==0)
            {
             y= -c1/b1;
             x= (-c2-y*b2)/a2;
            }
            else
            {
             y= (c1*a2-c2*a1)/(b2*a1-b1*a2);
             x= (-c1-y*b1)/a1;
            }

            r= sqr(x-x1)+sqr(y-y1); r= sqrt(r);
            o.setXY(x,y);
            //cout<<"method:    o="<<o<<"  r="<<r<<endl;
        #undef x1
        #undef x2
        #undef x3

        #undef y1
        #undef y2
        #undef y3

      }

      void printPolynom(std::ostream & os, int prec)
      {
        tPoint x= O.getX();
        tPoint y= O.getY();
        os<<fixed; os.precision(prec);

        os<<"x^2 + y^2";
        x*= 2; y*= 2;

        if (x>0) os<<" - "<<x;
        else if (x<0) os<<" + "<<-x;
        if (fabs(x)>eps) os<<"x";

        if (y>0) os<<" - "<<y;
        else if (y<0) os<<" + "<<-y;
        if (fabs(y)>eps) os<<"y";

        x/=2; y/=2;
        tPoint k= sqr(x)+sqr(y)-sqr(R);
        if (k>0) os<<" + "<<k;
        else if (k<0) os<<" - "<<-k;

        os<<" = 0";
      }


      void printBrackets(std::ostream & os, int prec)
      {
        tPoint x= O.getX();
        tPoint y= O.getY();
        os<<fixed; os.precision(prec);

        if (x>0) os<<"(x - "<<x<<")^2";
        else if (x<0) os<<"(x + "<<-x<<")^2";
        else os<< "x^2";
        os<<" + ";

        if (y>0) os<<"(y - "<<y<<")^2";
        else if (y<0) os<<"(y + "<<-y<<")^2";
        else os<< "y^2";

        os<<" = "<<R<<"^2";
      }


};


    template <typename tPoint, typename tR>
    std::istream & operator >>(std::istream & is, Circle<tPoint,tR> & c)
    {
        Point<tPoint> O;
        tR R;
        is>>O>>R;
        c.setO(O); c.setR(R);
        return is;
    }

    template <typename tPoint, typename tR>
    std::ostream & operator <<(std::ostream & os, Circle<tPoint,tR> & c)
    {
        Point<tPoint> O(c.getO());
        tR R(c.getR());

        os<<O<<" "<<R;
        return os;
    }


// end class Circle<tPoint,tR>







template <typename tPoint>
class Point
{

    protected:
     tPoint x;
     tPoint y;

    public:
     Point(tPoint x0, tPoint y0) { x= x0; y= y0; }
     Point()                     { x= 0;  y= 0;  }
     Point(const Point<tPoint> & p0)     { x= p0.x; y= p0.y;}

     tPoint getX() const           { return x; }
     void setX( tPoint x0)   { x= x0;    }

     tPoint getY() const            { return y; }
     void setY( tPoint y0)   { y= y0;    }

     void setXY(tPoint x0, tPoint y0) {x= x0; y= y0;}

     real distance(Point<tPoint> p2) //distance between this and p2
     {
        return sqrt(sqr(x-p2.x)+sqr(y-p2.y));
     }

     real distance0() const //distance between this and (0;0)
     {
        return sqrt(sqr(x)+sqr(y));
     }

    Point<tPoint> & operator = (Point<tPoint> & p2)
	{
		if(this != &p2)
		{
		    setX(p2.getX());
		    setY(p2.getY());
		}
		return *this;
	}
};



    template <typename tPoint>
    std::istream & operator >>(std::istream & is, Point<tPoint> &  p)
    {
        tPoint x0,y0;
        is>>x0>>y0;
        p.setX(x0);  p.setY(y0);
        return is;
    }

    template <typename tPoint>
    std::ostream & operator <<(std::ostream & os, Point<tPoint>  p)
    {
        os<<p.getX()<<" "<<p.getY();
        return os;
    }

    template <typename tPoint>
    bool operator==(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
        return (fabs(p1.getX()-p2.getX())<eps && fabs(p1.getY()-p2.getY())<eps );
    }

    template <typename tPoint>
    bool operator!=(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
        return !(p1==p2);
    }

/*
    template <typename tPoint>
    bool operator==(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
        if (p1.getX()==p2.getX() && p1.getY()==p2.getY()) return true;
        else return false;
    }

    template <typename tPoint>
    bool operator!=(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
        if (p1.getX()!=p2.getX() || p1.getY()!=p2.getY()) return true;
        else return false;
    }

*/
    template <typename tPoint>
    bool operator<(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
        if (p1.getY()<p2.getY()) return true;
        if (p1.getY()>p2.getY()) return false;
        return p1.getX()<p2.getX();
    }

    template <typename tPoint>
    bool operator>(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
     return (p2<p1);
    }

    template <typename tPoint>
    bool operator<=(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
     return (p1<p2 || p1==p2);
    }

    template <typename tPoint>
    bool operator>=(Point<tPoint>  & p1, Point<tPoint>  & p2)
    {
     return (p2<p1 || p1==p2);
    }



//end class Point<tPoint>











template <typename tPoint>
class Vector : public Point<tPoint>
{
  public:
      Vector()                                      : Point<tPoint> ()                                          {  }
      Vector(tPoint x0, tPoint y0)                  : Point<tPoint> (x0,y0)                                     {  }
      Vector(Point<tPoint> p)                       : Point<tPoint> (p)                                         {  }
      Vector(Point<tPoint> p1, Point<tPoint> p2)    : Point<tPoint> (p2.getX()-p1.getX(),p2.getY()-p1.getY())   {  }

  public:
      bool collinear(Vector<tPoint> v2)
      // if this collinear v2 return true else return false
      {
        if (fabs((*this).x*v2.y-(*this).y*v2.x)<eps) return true;
        else return false;
      }

      bool sameDirection(Vector<tPoint> v2)
      // if this has same direction with v2 return true else return false
      // WARNINGS!!!method doesn't check that vectors are collinear
      {
        if ( (  ( (*this).x>-eps && v2.x>-eps )  ||  ( (*this).x<eps && v2.x<eps )  ) &&
             (  ( (*this).y>-eps && v2.y>-eps )  ||  ( (*this).y<eps && v2.y<eps )  ) )
             return true;
        else return false;
      }

      int multiplyVectorSgn(Vector<tPoint> v2)
      { // if vectors multiply = 0  return 0, >0 return 1, <0 return -1
          tPoint t= (*this).x*v2.y-(*this).y*v2.x;
          if (fabs(t)<eps) return 0;
          if (t<eps) return -1;
          return 1;
      }

      tPoint multiplyVector(Vector<tPoint> v2)
      { // return vectors multiply
          return ((*this).x*v2.y-(*this).y*v2.x);
      }

      void makeVector(Point<tPoint> p1, Point<tPoint> p2)
      {// make Vector P1P2 ->
          (*this).setXY(p2.getX()-p1.getX(),p2.getY()-p1.getY());
      }
};

    template <typename tPoint>
    bool operator==(Vector<tPoint>  & v1, Vector<tPoint>  & v2)
    { // vectors are collinear and have same direction
        return (v1.collinear(v2) && v1.sameDirection(v2));
    }


//end class Vector<tPoint>

























template <typename tPoint>
class Segment
{
    protected:
     Point<tPoint> p1,p2;

    public:

     Segment()                                      { p1.setX(0); p1.setY(0);   p2.setX(0); p2.setY(0); }
     Segment(Point<tPoint> p10, Point<tPoint> p20)  { p1= p10;                  p2= p20;                }

     void setP1(Point<tPoint> p10)          { p1= p10;   }
     Point<tPoint> getP1()                  { return p1; }

     void setP2(Point<tPoint> p20)          { p2= p20;   }
     Point<tPoint> getP2()                  { return p2; }

     void setP1P2(Point<tPoint> p10, Point<tPoint> p20) { p1= p10; p2= p20; }

     void swapP1P2()
     {
         Point<tPoint> tmp;
         tmp= p1; p1= p2; p2= tmp;
     }

    Segment<tPoint> & operator = (Segment<tPoint> & sg2)
	{
		if(this != &p2)
		{
		    setP1(sg2.getP1());
		    setP2(sg2.getP2());
		}
		return *this;
	}

    bool contain(Point<tPoint> p)
    // if this contain p return true else return false
    {
     if (p1==p || p2==p) return true;
     Vector<tPoint> v1(p.getX()-p1.getX(),p.getY()-p1.getY()); // vector (P1;P)
     Vector<tPoint> v2(p.getX()-p2.getX(),p.getY()-p2.getY()); // vector (P2;P)

     return (v1.collinear(v2) && !v1.sameDirection(v2));
    }

    bool isIntersection(Segment<tPoint> sg2)
    {// if this intersections sg2 return true else return false
        if (contain(sg2.getP1()) || contain(sg2.getP2())) return true;
        if (sg2.contain(p1)      || sg2.contain(p2)     ) return true;

        Vector<tPoint> ab(p2.getX()-p1.getX(),p2.getY()-p1.getY()); //p1 - a, p2 - b
        Vector<tPoint> v1(sg2.p1.getX()-p1.getX(),sg2.p1.getY()-p1.getY());
        Vector<tPoint> v2(sg2.p2.getX()-p1.getX(),sg2.p2.getY()-p1.getY());

        if (ab.multiplyVectorSgn(v1)==ab.multiplyVectorSgn(v2)) return false; // if line AB doesn't intersect segment CD

        ab.setXY(sg2.p2.getX()-sg2.p1.getX(),sg2.p2.getY()-sg2.p1.getY());
        v1.setXY(p1.getX()-sg2.p1.getX(),p1.getY()-sg2.p1.getY());
        v2.setXY(p2.getX()-sg2.p1.getX(),p2.getY()-sg2.p1.getY());

        if (ab.multiplyVectorSgn(v1)==ab.multiplyVectorSgn(v2)) return false; // if line CD doesn't intersect segment AB

        v1.setXY(p2.getX()-p1.getX(),p2.getY()-p1.getY());
        if (!ab.collinear(v1)) return true;

        return false;
    }

    int intersection(Segment<tPoint> sg2, Point<tPoint> & O)
    // if don't intersection return -1
    // if intersection is one Point return 1, and set O this point
    // else return 0
    {
        if (!isIntersection(sg2)) return -1;
        int res;
        LineABC<tPoint,real> l1((*this)),l2(sg2);
        res= l1.intersection(l2,O);

        if (res==1) return 1; //lines have only one common point

        if (p1>p2) swapP1P2();
        if (sg2.p1>sg2.p2) sg2.swapP1P2();

        if (p1==sg2.p2) { O= p1; return 1; }
        if (p2==sg2.p1) { O= p2; return 1; }

        return 0;
    }

};



    template <typename tPoint>
    std::istream & operator >>(std::istream & is, Segment<tPoint> & sg)
    {
        Point<tPoint> p1,p2;
        is>>p1>>p2;
        sg.setP1(p1); sg.setP2(p2);
        return is;
    }

    template <typename tPoint>
    std::ostream & operator <<(std::ostream & os, Segment<tPoint> & sg)
    {
        Point<tPoint> p1(sg.getP1());
        Point<tPoint> p2(sg.getP2());
        os<<p1<<" "<<p2;
        return os;
    }

    template <typename tPoint>
    bool operator==(Segment<tPoint>  & sg1, Segment<tPoint>  & sg2)
    {
        if ( (sg1.getP1()== sg2.getP1() && sg1.getP2()== sg2.getP2()) ||
             (sg1.getP1()== sg2.getP2() && sg1.getP2()== sg2.getP1())  )
             return true;
        else return false;
    }

    template <typename tPoint>
    bool operator!=(Segment<tPoint>  & sg1, Segment<tPoint>  & sg2)
    {
        return (!(sg1==sg2));
    }




// end class Segment<tPoint>


















template <typename tPoint, typename tParam>
class LineABC
{
 private:
     tParam a,b,c;
 public:
    LineABC() : a(0),b(0),c(0)                                      {   }
    LineABC(tParam a0, tParam b0, tParam c0)  : a(a0),b(b0),c(c0)   {   }
    LineABC(Segment<tPoint> sg)
    {
       makeLineABC(sg.getP1(),sg.getP2(),a,b,c);
    }

    LineABC(Point<tPoint> A, Point<tPoint> B)
    {
       makeLineABC(A,B,a,b,c);
    }

    void setA(tParam A)                         { a= A;             }
    void setB(tParam B)                         { b= B;             }
    void setC(tParam C)                         { c= C;             }
    void setABC(tParam A, tParam B, tParam C)   { a= A; b= B; c= C; }

    tParam getA()   { return a; }
    tParam getB()   { return b; }
    tParam getC()   { return c; }
    void getABC(tParam & A, tParam & B, tParam & C)   { A= a; B= b; C= c; }

 private:
    static void makeLineABC(Point<tPoint> A, Point<tPoint> B, tParam & a, tParam & b, tParam & c)
    {
        if (A==B)
        { // points the same
          a= 0; b= 0; c= 0;
          throw ("Points the same! Can't build line");
          return;
        }

        a= B.getY()-A.getY();
        b= A.getX()-B.getX();
        c= B.getX()*A.getY()-A.getX()*B.getY();
        //cout<<"make Line: "<<A<<" , "<<B<<endl<<a<<" "<<b<<" "<<c<<endl<<endl;
        //cout<<"end"<<endl;
    }

 public:
    bool isIntersection(LineABC l2)
    {
        return !(fabs(a*l2.b-b*l2.a)<eps);
    }

    int intersection(LineABC l2, Point<tPoint> & O) //+
    // if don't intersection return -1
    // if intersection is one Point return 1, and set O this point
    // else return 0 (lines the same)
    {
        if ((*this)==l2) return 0;

        if (!isIntersection(l2))
        {
           // cout<<"Lines are parallel or same"<<endl;
            return -1;
        }

        real x,y;
        x= -((c*l2.b-b*l2.c)/(a*l2.b-b*l2.a));
        y= -((a*l2.c-c*l2.a)/(a*l2.b-b*l2.a));


        if (fabs(x)<eps) x= 0;
        if (fabs(y)<eps) y= 0;

        O.setXY((tPoint) x, (tPoint) y);
        return 1;
    }


    bool contain(Point<tPoint> p)
    {
        return (fabs(a*p.getX()+b*p.getY()+c)<eps);
    }

    tPoint distance(Point<tPoint> p)
    {
        return (fabs(a*p.getX()+b*p.getY()+c)/sqrt(sqr(a)+sqr(b)));
    }

/*
    Point<tPoint> intersection(Segment<tPoint> sg)
    {
      LineABC<tPoint,tParam> l2(sg.getP1(),sg.getP2());
      Point<tPoint> p= intersection(l2);
    }
*/

};




    template <typename tPoint, typename tParam>
    std::istream & operator >>(std::istream & is, LineABC<tPoint,tParam> & l)
    {
        tParam a,b,c;
        is>>a>>b>>c;
        l.setABC(a,b,c);
        return is;
    }

    template <typename tPoint, typename tParam>
    std::ostream & operator <<(std::ostream & os, LineABC<tPoint,tParam> & l)
    {
        tParam a,b,c;
        l.getABC(a,b,c);
        os<<a<<" "<<b<<" "<<c;
        return os;
    }


    template <typename tPoint, typename tParam>
    bool operator==(LineABC<tPoint,tParam>  & l1, LineABC<tPoint,tParam>  & l2)
    {
        tParam a1,b1,c1,a2,b2,c2;
        l1.getABC(a1,b1,c1);
        l2.getABC(a2,b2,c2);


        if (fabs(a1)>eps && fabs(a2)>eps)
        {
            b1/= a1; c1/= a1;
            b2/= a2; c2/= a2;
            return ((fabs(b1-b2)<eps)&&(fabs(c1-c2)<eps));
        }

        if (fabs(b1)>eps && fabs(b2)>eps)
        {
            a1/= b1; c1/= b1;
            a2/= b2; c2/= b2;
            return ((fabs(a1-a2)<eps)&&(fabs(c1-c2)<eps));
        }

        if (fabs(c1)>eps && fabs(c2)>eps)
        {
            a1/= c1; b1/= c1;
            a2/= c2; b2/= c2;
            return ((fabs(a1-a2)<eps)&&(fabs(b1-b2)<eps));
        }

        return false;
    }


    template <typename tPoint, typename tParam>
    bool operator!=(LineABC<tPoint,tParam>  & l1, LineABC<tPoint,tParam>  & l2)
    {
        return !(l1==l2);
    }



// end class LineABC<tPoint,tParam>
















template <typename tPoint>
class Ray
{
   private:
       Point<tPoint> p; // begin of ray
       Vector<tPoint> v; // directive vector
   public:
     Ray()  : p(),v() {}
     Ray(Point<tPoint> p0, Vector<tPoint> v0)  : p(p0),v(v0) {  }

     void setP(Point<tPoint> p0)                            { p= p0;        }
     void setV(Vector<tPoint> v0)                           { v= v0;        }
     void setPV(Point<tPoint> p0, Vector<tPoint> v0)        { p= p0; v= v0; }

    Point<tPoint> getP()   { return p; }
    Vector<tPoint> getV()                               { return v;     }
    void getPV(Point<tPoint> & p0, Vector<tPoint> & v0)  { p0= p; v0= v; }

    bool contain(Point<tPoint> x)
    {
      if (p==x) return 1;
      Vector<tPoint> v1(x.getX()-p.getX(),x.getY()-p.getY());
      return v==v1;
    }
};



    template <typename tPoint>
    std::istream & operator >>(std::istream & is, Ray<tPoint> & r)
    {
        Point<tPoint> p;
        Vector<tPoint> v;
        is>>p>>v;
        r.setPV(p,v);
        return is;
    }

    template <typename tPoint>
    std::ostream & operator <<(std::ostream & os, Ray<tPoint> & r)
    {
        os<<r.getP()<<" "<<r.getV();
        return os;
    }


// end class Ray<tPoint>












template<typename tPoint>
bool comparePointsPolarAngle(const Point<tPoint> &p1,const Point<tPoint> &p2)
{
 tPoint t= p1.getY()*p2.getX()-p1.getX()*p2.getY();
 if (fabs(t)<eps)
 {
     return (p1.distance0()<p2.distance0());
 }

 return (t<0);
}


template<typename tPoint>
class Polygon
{

    template <typename t>
    friend std::ostream & operator <<(std::ostream & os, Polygon<t> & pl);

    template <typename t>
    friend std::istream & operator >>(std::istream & is, Polygon<t> & pl);

 private:
    int n;
    Point<tPoint> *arr;


 public:
    int getN() {return n;}
    Polygon() : n(0), arr(NULL) { }
    Polygon(int n0, Point<tPoint> *arr0)
    {
        makePolygon(n0,arr0);
    }

    Polygon(int n0, Point<tPoint> *arr0, bool isPolygon)
    // if isPolygon==true
    // if isPolygon==false
    // 1 make convex hull return it
    {
        if (isPolygon || n<3) { makePolygon(n0,arr0); return; }
        int n1;
        Point<tPoint> *arr1= new Point<tPoint>[n0];
        makeConvexHull(n0,arr0,n1,arr1);

        n= n1;
        delete [] arr;
        arr= new Point<tPoint> [n1];
        for (int i=0; i<n1; i++)
            arr[i]= arr1[i];
        delete [] arr1;

    }

 private:
    void makePolygon(int n0, Point<tPoint> *arr0)
    {
        n= n0;
        delete [] arr;
        arr= new Point<tPoint>[n];
        for (int i=0; i<n; i++)
            arr[i]= arr0[i];
    }

 public:
    static void makeConvexHull(int n0, Point<tPoint> *arr0, int & n1, Point<tPoint> *arr1)// n0 - numbers of Points in the arr0
    { // in arr1 we have at least n0 elements and return n1 - number of used elements
      Point<tPoint> p;
      p= arr0[0];
      for (int i=1; i<n0; i++)     // find p - the most bottom left point
        if (arr0[i]<p) p= arr0[i];

      // convex always consist p
      relocation(n0,arr0,p);

      // sort Point by polar angle
      sortPolarAngle(n0, arr0);

      arr1[0]= arr0[0];
      int i2= 1;
      while (i2<n0 && arr0[i2]==arr0[0]) i2++;
      arr1[1]= arr0[i2];
      Vector<tPoint> v1(arr1[1]);
      Vector<tPoint> v2;
      int k=1;// index of last element in arr1 (convex hull)
      for (int i= i2+1; i<n0; i++)
      if (arr0[i]!=arr0[i-1])
      {
          v2.setXY(arr0[i].getX()-arr1[k].getX(),arr0[i].getY()-arr1[k].getY());

          while (v1.multiplyVectorSgn(v2)<0)
          {// right turn
            k--;
            v1.setXY(arr1[k].getX()-arr1[k-1].getX(),arr1[k].getY()-arr1[k-1].getY());
            v2.setXY(arr0[i].getX()-arr1[k].getX(),arr0[i].getY()-arr1[k].getY());
          }

          if (v1.multiplyVectorSgn(v2)>=0)
          {// left turn
            arr1[++k]= arr0[i];
            v1= v2;
          }

      } // for (int i=2; i<n0; i++)

      n1= k+1;
      p.setXY(-p.getX(),-p.getY());
      relocation(n0,arr0,p);
      relocation(n1,arr1,p);
    }






    static void relocation(int n0, Point<tPoint> *arr0, Point<tPoint> p0) // n0 - numbers of Points in the arr0
    {// relocate Points in the array in way, where p0 transfer to (0;0)
      tPoint x,y;
      x= p0.getX(); y= p0.getY();
      for (int i=0; i<n0; i++)
          arr0[i].setXY(arr0[i].getX()-x,arr0[i].getY()-y);
    }


    static void sortPolarAngle(int n0, Point<tPoint>* arr0)
    {
      sort(arr0,arr0+n0,comparePointsPolarAngle<tPoint>);
    }



    real perimeter()
    {
        if (n<2) return 0;
        real ans= 0;
        ans= arr[0].distance(arr[n-1]);
        for (int i=n-1; i>0; i--)
            ans+= arr[i].distance(arr[i-1]);
        return ans;
    }


    real area()
    {
        if (n<3) return 0;
        real s= 0;
        for (int i=n-2; i>=0; i--)
            s+= (arr[i+1].getY()+arr[i].getY())*(arr[i+1].getX()-arr[i].getX());
        s+= (arr[0].getY()+arr[n-1].getY())*(arr[0].getX()-arr[n-1].getX());

        s/= 2.0;

        if (s<0) s= -s;
        return s;
    }


    Point<real> centerOfGravity(string param)
    // param = "apex" || "side" || "all"
    {
       if (param!= "apex" && param!= "side" && param!= "all") throw ("incorrect parameter!");

       if (param=="all") return centerOfGravityAll();
    }
 private:

    Point<real> centerOfGravityAll()
    {
        real S;
        S= area()*6;
        real x= 0, y= 0;
        #define X getX()
        #define Y getY()

        for (int i=n-2; i>=0; i--)
        {
            x+= (arr[i].X+arr[i+1].X)*(arr[i].X*arr[i+1].Y-arr[i+1].X*arr[i].Y);
            y+= (arr[i].Y+arr[i+1].Y)*(arr[i].X*arr[i+1].Y-arr[i+1].X*arr[i].Y);
        }

        x+= (arr[n-1].X+arr[0].X)*(arr[n-1].X*arr[0].Y-arr[0].X*arr[n-1].Y);
        y+= (arr[n-1].Y+arr[0].Y)*(arr[n-1].X*arr[0].Y-arr[0].X*arr[n-1].Y);

        #undef X
        #undef Y

        x/= S;   y/= S;
        Point<real> p(x,y);
        return p;
    }

    static void printTest(int n0,  Point<tPoint> *arr0, Point<tPoint> p)
    {
      p.setXY(-p.getX(),-p.getY());
      relocation(n0,arr0,p);

        for (int j=0; j<n0; j++)
            cout<<arr0[j]<<", ";
        cout<<endl<<endl;

      p.setXY(-p.getX(),-p.getY());
      relocation(n0,arr0,p);
    }
};


    template <typename tPoint>
    std::ostream & operator << (std::ostream & os, Polygon<tPoint> & pl)
    {
        for (int i=0; i<pl.n; i++)
            os<<pl.arr[i]<<" ";
        return os;
    }

    template <typename tPoint>
    std::istream & operator >> (std::istream & is, Polygon<tPoint> & pl)
    {
        is>>pl.n;
        delete [] pl.arr;
        pl.arr= new Point<tPoint> [pl.n];
        for (int i=0; i<pl.n; i++)
            is>>pl.arr[i];
        return is;
    }

//end class Polygon<tPoint>























template <typename tPoint>
class Triangle
{
    template <typename t>
    friend std::istream & operator >>(std::istream & is, Triangle<t> & tr);

    template <typename t>
    friend std::ostream & operator <<(std::ostream & os, Triangle<t> tr);

  private:
     Point <tPoint> A,B,C;

  public:
    Triangle() : A(),B(),C() { }
    Triangle(Point<tPoint> A0, Point<tPoint> B0, Point<tPoint> C0) :  A(A0), B(B0), C(C0)  { }

    Point<tPoint> getA()    { return A; }
    Point<tPoint> getB()    { return B; }
    Point<tPoint> getC()    { return C; }
    void getABC(Point<tPoint> & A0, Point<tPoint> & B0, Point<tPoint> & C0) { A0= A; B0= B; C0= C; }

    void setA(Point<tPoint> A0)  { A= A0; }
    void setB(Point<tPoint> B0)  { B= B0; }
    void setC(Point<tPoint> C0)  { C= C0; }
    void setABC(Point<tPoint> A0, Point<tPoint> B0, Point<tPoint> C0) { A= A0; B= B0; C= C0; }

    int contain(Point<tPoint> p)
    // return 1 if p in
    // return 0 if p on the side
    // return -1 if p out of
    {
      { // point on the side of triangle
        Segment<tPoint> sg;
        sg.setP1P2(A,B); if (sg.contain(p)) return 0;
        sg.setP1P2(A,C); if (sg.contain(p)) return 0;
        sg.setP1P2(B,C); if (sg.contain(p)) return 0;
      }

      Vector<tPoint> v1,v2;
      int sgn;

      v1.makeVector(p,A); v2.makeVector(A,B);
      sgn= v1.multiplyVectorSgn(v2);

      v1.makeVector(p,B); v2.makeVector(B,C);
      if (sgn!= v1.multiplyVectorSgn(v2)) return -1;

      v1.makeVector(p,C); v2.makeVector(C,A);
      if (sgn!= v1.multiplyVectorSgn(v2)) return -1;

      return 1;
    }

    bool isVertex(Point<tPoint> p)
    {
        return (p==A || p==B || p==C);
    }


    Polygon<tPoint> intersectionTriangle( Triangle<tPoint> tr )
    {
        int n=0;
        Point<tPoint> *arr= new Point<tPoint> [20];

        #define s(q,w) (Segment<tPoint>(q,w))
            intersectionSide(s(A,B),s(tr.A,tr.B),arr,n);
            intersectionSide(s(A,C),s(tr.A,tr.B),arr,n);
            intersectionSide(s(B,C),s(tr.A,tr.B),arr,n);

            intersectionSide(s(A,B),s(tr.A,tr.C),arr,n);
            intersectionSide(s(A,C),s(tr.A,tr.C),arr,n);
            intersectionSide(s(B,C),s(tr.A,tr.C),arr,n);

            intersectionSide(s(A,B),s(tr.B,tr.C),arr,n);
            intersectionSide(s(A,C),s(tr.B,tr.C),arr,n);
            intersectionSide(s(B,C),s(tr.B,tr.C),arr,n);
        #undef s

        //cout<<1<<endl;
        if (contain(tr.A)!=-1) arr[n++]= tr.A;
        if (contain(tr.B)!=-1) arr[n++]= tr.B;
        if (contain(tr.C)!=-1) arr[n++]= tr.C;
        //cout<<2<<endl;

        if (tr.contain(A)!=-1) arr[n++]= A;
        if (tr.contain(B)!=-1) arr[n++]= B;
        if (tr.contain(C)!=-1) arr[n++]= C;
        //cout<<3<<endl;

/*
        for (int i=0; i<n; i++)
            cout<<arr[i]<<", ";
        cout<<endl;
        cout<<"end 3"<<endl;
        */

        Polygon<tPoint> pl(n,arr,false);
        //cout<<4<<endl;
        return pl;
    }

  private:
    static void intersectionSide(Segment<tPoint> sg1, Segment<tPoint> sg2, Point<tPoint> *arr , int & n)
    {
       int res;
       Point<tPoint> O;
       res= sg1.intersection(sg2,O);

       if (res!=1) {return;}
       arr[n++]= O;
       //cout<<"intersectionSide: "<<sg1<<", "<<sg2<<endl<<endl<<O<<endl;
    }

};


    template <typename tPoint>
    std::istream & operator >>(std::istream & is, Triangle<tPoint> & tr)
    {
        is>>tr.A>>tr.B>>tr.C;
        return is;
    }

    template <typename tPoint>
    std::ostream & operator <<(std::ostream & os, Triangle<tPoint> tr)
    {
        os<<tr.A<<" "<<tr.B<<" "<<tr.C;
        return os;
    }

// end class Triangle<tPoint>











int main()
{

 ios_base::sync_with_stdio(0);
 cin.tie(0);
// LL a[110];
// memset(a,0,sizeof(a));

  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
 srand(__rdtsc());

 cout<<fixed;
 cout.precision(8);
 /*

 Point<int> p,p2;

 Vector<int> v,v2;
 while (cin>>v>>v2)
 {
     cout<<"col= "<<v.collinear(v2)<<endl;
     cout<<"dir= "<<v.sameDirection(v2)<<endl;
     cout<<"eqv= "<<(v==v2)<<endl;
     cout<<"sgn= "<<v.multiplyVectorSgn(v2)<<endl;
 }
 Vector<int> v3(1,2);

 Segment<int> s1,s2;
 while (cin>>s1>>s2)
    cout<<s1.intersection(s2)<<endl;

 Point<long double> A,B,C;

 while (cin>>A>>B>>C)
 {
     Circle<long double,long double> c(A,B,C);
     //cout<<"points: "<<A<<" , "<<B<<",  "<<C<<endl;
     //cout<<"circle:  "<<c<<endl;

     c.printBrackets(cout,3);
     cout<<endl;
     c.printPolynom(cout,3);
     cout<<endl<<endl;
 }


 Point<double> p,p1,p2;
 LineABC<double,double> l;


 cout<<fixed;
 cout.precision(2);

 while (cin>>p>>p1>>p2)
 {
    Vector<double> v(p1,p2);
    Ray<double> r(p1,v);
    if (r.contain(p)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
 }


 Point<long double> p,p1,p2;
 while (cin>>p>>p1>>p2)
 {
  LineABC<long double,long double> l(p1,p2);
  cout<<l.distance(p)<<endl;
 }

 Point<int> p1,p2;

 while (cin>>p1>>p2)
 {
     cout<<(p1<p2)<<endl;
 }

 cout<<fixed;
 cout.precision(1);

 Point<int> arr[100];
 Point<int> arr1[100];
 int n,n1;

 cin>>n;
 for (int i=0; i<n; i++)
    cin>>arr[i];

 Polygon<int> p(n,arr,false);
 //cout<<p<<endl;
 cout<<p.perimeter()<<endl;
 //p.sortPolarAngle(5,arr);
 //sort(arr,arr+5,comparePointsPolarAngle<int>);
 p.makeConvexHull(n,arr,n1,arr1);
 cout<<endl;
 for (int i=0; i<n1; i++)
    cout<<arr1[i]<<endl;
 cout<<endl;

 cout.precision(3);
 Polygon<int> pl;
 cin>>pl;
 cout<<pl.area()<<endl;


 int n;
 Point<int> arr[110];
 while (cin>>n && n>=3)
 {
     for (int i=0; i<n; i++)
        cin>>arr[i];

cout<<"asdasd"<<endl;
     Polygon<int> pl(n,arr,false);
cout<<"after"<<endl;
     cout<<pl.centerOfGravity("all");
 }
*/

 Triangle<dbl> tr,tr2;
 cout.precision(2);
 while (cin>>tr>>tr2)
 {
    Polygon<dbl> pl= tr.intersectionTriangle(tr2);
    cout<<pl<<endl<<endl;
    cout<<pl.getN()<<" "<<pl.area()<<endl;
 }
 return 0;
}


