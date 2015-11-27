/* Teleoperation System for Mobile Manipulators Framework
 *
 * Copyright (C) 2015 
 * RECONFIGURABLE CONTROL OF ROBOTIC SYSTEMS OVER NETWORKS Project
 * Robotics and Control Systems Laboratory
 * Department of Electrical Engineering
 * Sapientia Hungarian University of Transylvania
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * For more details see the project homepage:
 * <http://www.ms.sapientia.ro/~martonl/MartonL_Research_TE.htm>
 */


#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

namespace Utils
{
  /**
   * Template function used to limit the elements of a given array.
   * @param[in,out] elements The array containing the elements.
   * @param[in] elementsCount The number of elements
   * @param[in] limit The limit value. Each element is limited between (-limit, +limit)
   */
  template <typename T>
  void ClampFunction(T* elements, unsigned int elementsCount, T limit)
  {
    for(unsigned int i = 0; i < elementsCount; i++)
    {
      if (elements[i] > limit)
      {
        elements[i] = limit;
      }
      else if (elements[i] < -limit)
      {
        elements[i] = -limit;
      }
    }
  }

  /**
   * Template function used to print the elements of a given array
   * @param[in] title The title of the print.
   * @param[in] elements The array containing the elements.
   * @param[in] elementsCount The number of elements
   * @param[in] limit The limit value. Each element is limited between (-limit, +limit)
   * @param[in] width The print width of each element
   * @param[in[ precision The print precision of each element
   */
  template <typename T>
  void PrintVector(std::string title, T* elements, unsigned int elementsCount, unsigned int width = 10, unsigned int precision = 4)
  {
    cout << setw(width) << title;

    for (unsigned int i = 0; i < elementsCount; i++)
    {
      cout << fixed << setw(width) << setprecision(precision) << elements[i];
    }

    cout << endl;
  }

} // end namespace

#endif // UTILITIES_H
