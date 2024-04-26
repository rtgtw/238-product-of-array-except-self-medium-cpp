/*


Product of Array Except Self

*/

#include <iostream>
#include <vector>





class Solution {

public:
	std::vector<int> productExceptSelf(std::vector<int>& nums);
};



std::vector<int> Solution::productExceptSelf(std::vector<int>& nums) {

	//Create an output array
	std::vector<int> output;

	//Create a counter variable and initialize it to 1;
	int counter = 1;

	//First thing we have to do is insert the multipled prefixes of each element
	//Since there is no prefix for the first element we can initialize count to 1
	//we can use a for loop to iterate through the array

	output.insert(output.begin(), counter);
	//Prefix inserted in output
	for (int i = 1; i < nums.size(); i++) {
		output.push_back(counter * nums[i - 1]);
		counter = output[i];
	}


	//Initialize postfix, which is output.size-1 's result,
	//reset counter
	counter = 1;
	output[output.size() - 1] = counter * output[output.size() - 1];
	//Postfix inserted in output
	for (int i = output.size() - 2; i >= 0; i--) {

		int temp;
		//Postfix number needed
		temp = counter * nums[i + 1];
		output[i] = temp * output[i];
		counter = temp;

	}


	//Now we can just return the output array
	return output;



}


int main() {
	
	Solution solution;

	std::vector<int> array = { 1,2,3,4 };
	std::vector<int> array1 = { -1,1,0,-3,3 };

	std::vector<int> result = solution.productExceptSelf(array1);

	for (int x : result) {
		std::cout << x << ' ';
	}

	//Time O(n), space O(1), no data structure was used to store anything
	//only structure created was a vector for the results

	return 0;
}



/*

std::vector<int> Solution::productExceptSelf(std::vector<int>& nums) {

	//Create an output array
	std::vector<int> output;

	//Create a counter variable and initialize it to 1;
	int counter = 1;

	//First thing we have to do is insert the multipled prefixes of each element
	//Since there is no prefix for the first element we can initialize count to 1
	//we can use a for loop to iterate through the array

	output[0] = counter;
	//Prefix inserted in output
	for (int i = 1; i < nums.size(); i++) {
		output[i] = counter * nums[i - 1];
		counter = output[i];
	}


	//Initialize postfix, which is output.size-1 's result,
	output[output.size() - 1] = counter * output[output.size() - 1];
	//Postfix inserted in output
	for (int i = output.size() - 2; i > 0; i--) {

		int temp;
		//Postfix number needed
		temp = counter * nums[i + 1];
		output[i] = temp * output[i];
		counter = temp;

	}


	//Now we can just return the output array
	return output;
}*/