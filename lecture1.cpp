//Google style: bracket starts on same line, 2 space tabs
//Review defining an ADT for a dynamic data container
//A true ADT has no code body inside it, which makes derivation easier

//template <class TYPE> // not doing templated version
class dynamicArray {

  int length;    //track number of stored values
  int capacity;  //track total capacity
  float *dArray;  //data

  void resize(); //function to resize the array

public:
  //Default constructor base member initialization
  //this is a different way of doing it, can be done inside in the constructor.
  dynamicArray() : length {0}, capacity {1}, dArray {new float[capacity]} {}

  //Constructor with capacity specified
  //Google Style - we add explicit in constructors with named parameters to prevent
  //    implicit conversions when there is no stated default constructor. Here we do not
  //    need to add explicit as we have defined our default constructor
  dynamicArray(int cap) : length {0}, capacity {cap}, dArray {new float[capacity]} {}

  void display() {      //function to print all the stored values in order from first to last, in one line
    for ( int i = 0; i < length; ++i )
      std::cout << dArray[i] << " ";

    std::cout << std::endl;
  }

  void append(float x) {    //appends a value to the end of the "array", resizing if necessary
    if ( length == capacity )
      resize();

    dArray[length++] = x; //the post-increment saves a line of code.
    //length++; //is the saved line of code from adding the postincrement in the previous line
  }

  void insert(int index, float x) { //resizes "array" and shifts values down to make room for inserted value
      while ( capacity < index || length == capacity )
        resize();

      if ( index > length ) {
        length = index;
      } else {
        for ( int i = length; i > index; --i )
          dArray[i+1] = dArray[i];
        length++;
      }
      dArray[index] = x;
  }

  float deleteItem(int index) {  //removes an element from the "array" and shifts the other elements to keep continuity
    float temp = NAN; //NAN == Not A Number: specific to floats. does not jive with templated datatypes

    if (index < length) {
      temp = dArray[index];
      for( int i = index; i < length; ++i )
        dArray[i] = dArray[i+1];
      --length;
    }
    return temp;
  }

  int linearSearch(float x, float e) { //assumes array is not sorted, searches for input item one element at a time and returns index location of match
    for ( int i = 0; i < length; ++i ) {
      if ( abs(dArray[i] - x) < e)
        return i;
    }
    return -1;
  }

  int binarySearch(float x) { //assumes array is SORTED. goes to the midpoint of "array" and determines which direction it needs to
                              //move to find its value.
  }

};
//REVIEW AUTO
