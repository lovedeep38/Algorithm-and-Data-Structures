class Circle{
    public:
        Circle();  //default constructor
        Circle(int x, int y, double radius);  //constructor with parameters
        int getX() const;   //getter for x coordinate
        int getY() const;   //getter for y coordinate
        double getRadius() const;   //getter for radius
        
        void translateXY(int x, int y);  //translate x and y coordinates
        void setRadius(double radius);  //setter for radius
        double computeArea() const;     //compute area of circle
        void displayCircle() const;     //display the circle

        bool intersect(Circle c2) const;    //check if two circles intersect

        static int getNumberOfCurrentCircles();     //get number of current circle objects created

        static int getCirclesOnLeftOfYAxis();       //get number of circles on left of y axis

        bool checkLeft() const;         //check if circle is on left of y axis

    private:
        int x;      //x coordinate
        int y;      //y coordinate
        double radius;      //radius of circle
        static int totalCircles;    //counter for total number of circles created
        static int countForYAxis;   //counter for number of circles on left of y axis
        
};

