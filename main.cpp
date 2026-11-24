#include <iostream>

template <typename T> //create template
class GenericArray  //create template class
{
  private:  //create private variables section
    T *data;  //pointer to array
    int arraySize; //variable to track array size

  public: // create public variables section
    GenericArray() //create default constructor
    {
      data = nullptr;  //set array pointer to nullptr
      arraySize = 0;  //set array size to zero
    }

    void addElement(T param)  //function to add a value to the end of the array
    {
      T *newData = new T[arraySize + 1];  //allocate new array with space for extra value
      for (int i = 0; i < arraySize; i++)  //loop through existing values
      { newData[i] = data[i]; }  //copy previous value to new array
      newData[arraySize] = param;  //assign new value to the end of the new array
      delete[] data;  //delete old array to free memory
      data = newData;  //point data to the new array
      arraySize++ ;  //increment array size counter
    }

    T at(int param) const //function to return value at given index
    {
      if (param < 0 || param >= arraySize) //check if index is out of bounds
      {
        std::cout << "Index " << param << " is out of bounds." << std::endl;  //output bounds error message
        return T(); //return default zero value for type T
      }
      return data[param];  //return value at specified index
    }

    int size() const  //function to return current  array size
    { return arraySize; } //return arraySize variable

    T sum() const  //function to sum all values in array
    {
      T total = 0;  //set running sum to zero
      for (int i = 0; i < arraySize; i++)  //loop through all array values
      { total = total + data[i]; }  //add current value to running sum
      return total;  //return total sum
    }

    T max() const  //function to find maximum value in array
    {
      if (arraySize == 0)  //check if array is empty
      {
        std::cout << "Array is empty, max is undefined." << std::endl;  //output empty array error
        return T();  //return default zero value for type T
      }
      T maxVal = data[0];  //set maxVal to first value
      for (int i = 1; i < arraySize; i++)  //loop through remaining values
      {
        if (data[i] > maxVal)  //check if current value is greater than maxVal
        { maxVal = data[i]; }  //update maxVal
      }
      return maxVal;  //return maximum value
    }

    T min() const //function to find minimum value in the array
    {
      if (arraySize == 0)  //check if array is empty
      {
        std::cout << "Array is empty, min is undefined." << std::endl;  //output empty array error
        return T();  //return default zero value for type T
      }
      T minVal = data[0];  //set minVal to first element
      for (int i = 1; i < arraySize; i++)  //loop through remaining values
      {
        if (data[i] < minVal)  //check if current value is less than minVal
        { minVal = data[i]; }  //update minVal
      }
      return minVal;  //return minimum value
    }

    T* slice(int begin, int end) const  //function to return array slice from beginning to end
    {
      if (begin < 0 || end >= arraySize || begin > end)  //check if slice bounds are valid
      {
        std::cout << "Invalid slice bounds (" << begin << ", " << end << ")." << std::endl;  //output bounds error message
        return nullptr;  //return nullptr for invalid slice
      }
      int sliceSize = end - begin + 1;  //calculate number of values in slice
      T *slicedData = new T[sliceSize];  //allocate array for the slice
      for (int i = 0; i < sliceSize; i++)  //loop through slice range
      { slicedData[i] = data[begin + i]; }  //copy values from original array to slice
      return slicedData;  //return pointer to newly allocated slice array
    }

    virtual ~GenericArray() //create destructor
    { delete[] data; } //free dynamically allocated array memory
};

int main()  //main entry point
{
  std::cout << "\n*** GenericArray<int> Test ***" << std::endl; //output int test header
  GenericArray<int> int_array;  //create GenericArray object for ints

  for (int i = 0; i <= 10; i++)  //loop to populate int_array with  11 values
  { int_array.addElement(i * 2); }  //add even integers 0 through 20

  std::cout << "Elements in int_array: ";  //output values label
  for (int i = 0; i < int_array.size(); i++)  //loop through int_array
  { std::cout << int_array.at(i) << " "; }  //output each value using at function
  std::cout << std::endl;  //end values line

  std::cout << "size of array is " << int_array.size() << std::endl;  //output size of int_array
  std::cout << "sum of the array is " << int_array.sum() << std::endl;  //output sum of int_array
  std::cout << "maximum and minimum of array is " << int_array.max() << "\t" << int_array.min() << std::endl;  //output max and min values

  int beginIdx = 5;  //define slice start index
  int endIdx = 10;  //define slice end index
  int *sliced_array = int_array.slice(beginIdx, endIdx);  //create sliced array from index 5 to 10
  if (sliced_array != nullptr) //verify slice succeeded before printing
  {
    std::cout << "sliced_array (" << beginIdx << " to " << endIdx << "): ";  //output slice label
    for (int i = 0; i <= (endIdx - beginIdx); i++)  //loop through sliced array values
    { std::cout << sliced_array[i] << " "; } //output each sliced value
    std::cout << std::endl;  //end slice line
    delete[] sliced_array;  //free slice memory
  }

  std::cout << "\n*** GenericArray<double> Test ***" << std::endl;  //output double header
  GenericArray<double> double_array;  //create GenericArray object for doubles
  double_array.addElement(1.5);  //add 1st double value
  double_array.addElement(4.25); //add 2nd double value
  double_array.addElement(-2.75);  //add 3rd double value
  double_array.addElement(9.8);  //add 4th double value
  double_array.addElement(3.1);  //add 5th double value

  std::cout << "size of array is " << double_array.size() << std::endl;  //output size of double_array
  std::cout << "sum of the array is " << double_array.sum() << std::endl;  //output sum of double_array
  std::cout << "maximum and minimum of array is " << double_array.max() << "\t" << double_array.min() << std::endl; //output max and min

  double *sliced_double = double_array.slice(1, 3);  //create sliced double array from index 1 to 3
  if (sliced_double != nullptr)  //verify slice succeeded before printing
  {
    std::cout << "sliced_double (1 to 3): ";  //output double slice label
    for (int i = 0; i <= (3 - 1); i++)  //loop through sliced double values
    { std::cout << sliced_double[i] << " "; }  //output each sliced double value
    std::cout << std::endl;  //end slice line
    delete[] sliced_double; //free double slice memory
  }

  std::cout << "\n*** Out-of-Bounds Check ***" << std::endl;  //output bounds check header
  int *invalid_slice = int_array.slice(8, 20);  //test out-of-bounds slice handling
  if (invalid_slice != nullptr)  //verify pointer before deleting
  { delete[] invalid_slice; }  //free memory any memory

  std::cout << std::endl; //output newline
  return 0; //return zero
}

