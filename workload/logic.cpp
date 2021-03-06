/* Copyright 2020 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <string>
#include "logic.h"

std::string checkParity(std::string decrypted_user_input_str) {

    try {
        int number = std::stoi(decrypted_user_input_str);

        std::string result = "Number " + std::to_string(number) + " is ";

        if(number % 2 == 0)
            result += "even";
        else
            result += "odd";

        return result;
    } catch (std::invalid_argument& ia) {
        return "Invalid input data";
    }

}
