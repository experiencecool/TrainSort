# TrainSort
Sorting algorithm that uses stacks (LIFO - Last In First Out - structure)

# Input/Output examples

Input file:
<p>
  <img src="https://github.com/experiencecool/TrainSort/blob/34edb9249411db92ad406b6c784aae7a0eca9eef/Images/input.png">
</p>
<p>
   '5' - number of reilcars <br>
   '4 3 1 2 7' - list of railcars
</p>
 Output example:<br>
 first iterration
 <p>
  
  <img src="https://github.com/experiencecool/TrainSort/blob/master/Images/output.png"></p>
 <ul>Legend: <br>
 '^[number]' = get element from LIFO <br>
 '![number]' = put elements in LIFO   <br>
 'remembered [number]' = remember  the smalest element <br>
                 <br><br>
  format of output: [number of railcar] [action] [number of rails]
  </ul>
  
# Discription

<p>
  <img src="https://github.com/experiencecool/TrainSort/blob/master/Images/869.jpg">
  </p>
  <br>
  <p>
  The main problem is to sort the railcars while have only 3 railroads. LIFO emulates railroads, and elements emulate railcars. All elements from the first stack moves to the second. At the same time we are looking for the smalest element and remember its index. Than we puts elements from the second LIFO to the first but smallest goes to the third railway. At the end we have railcars sorted from smallest to largest.
  </p>
