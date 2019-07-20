//
// Created by leonard on 7/20/19.
//

#include "LinkedList.h"
#include <iostream>

bool Size_ListEmpty_Returns0(){
    LinkedList<int> list = LinkedList<int>();

    int check = list.size();
    return check == 0;
}

bool Size_ThreeNodeInList_Returns3(){
    LinkedList<int> list = LinkedList<int>();
    list.add(1);
    list.add(2);
    list.add(3);


    return list.size() == 3;

}

bool Add_Place0_ListEmpty_ReturnsSize(){
    LinkedList<int> list = LinkedList<int>();

    int check = list.add(0,1);
    return check == 1;

}

bool Add_PlaceLargerThanSize_OneElementInList_AddNodeAtTheEnd(){
    LinkedList<int> list = LinkedList<int>();
    list.add(1);

    //Act
    list.add(5, 2);
    list.add(4, 3);

    if(list.get(0) != 1){
        return false;
    }
    if(list.get(1) != 2){
        return false;
    }
    return list.get(2) == 3;
}

bool Unshift_ListEmpty_ReturnSize1(){
    //Arrange
    LinkedList<int> list = LinkedList<int>();

    //Act
    int check = list.unshift(1);
    return check == 1;
}

bool Unshift_OneNodeInList_ReturnSize2(){
    LinkedList<int> list = LinkedList<int>();
    list.add(3);

    //Act
    int check = list.unshift(1);
    return check == 2;
}

bool Unshift_OneNodeInList_ExistingNodeShifted(){
    LinkedList<int> list = LinkedList<int>();
    list.add(1);

    //Act
    list.unshift(2);

    if(list.get(0) !=2){
        return false;
    }
    return list.get(1) == 1;
}

bool Set_ListEmpty_ReturnsFalse(){
    LinkedList<int> list = LinkedList<int>();

    try{
        list.set(-1, 1);
        return false;
    }catch (const std::out_of_range &e){

    }
    try{
        list.set(0, 1);
        return false;
    }catch (const std::out_of_range &e){

    }

    try{
        list.set(1, 1);
        return false;
    }catch (const std::out_of_range &e){
        return true;
    }
}

bool Set_ThreeNodeInList_ModifyNode(){
    LinkedList<int> list = LinkedList<int>();
    list.add(0);
    list.add(1);
    list.add(2);

    list.set(1, 10);

    return list.get(0) == 0 && list.get(1) == 10 && list.get(2) == 2;
}

bool Pop_ListEmpty_ReturnsNull(){
    LinkedList<int> list = LinkedList<int>();

    return list.pop() == NULL;
}

bool Pop_TwoNodesInList_ReturnsLastNode(){
    LinkedList<int> list = LinkedList<int>();
    list.add(0);
    list.add(1);

    return list.pop()== 1;
}

bool Pop_TwoNodesInList_ListIsShorter(){
    LinkedList<int> list = LinkedList<int>();
    list.add(0);
    list.add(1);

    //Act Assert
    if(list.size() != 2){
        return false;
    }
    list.pop();
    return list.size() == 1;
}

bool Shift_ListEmpty_ReturnsNull(){
    LinkedList<int> list = LinkedList<int>();

    return list.shift() == NULL;
}

bool Shift_OneNodeInList_ReturnsData(){
    LinkedList<int> list = LinkedList<int>();
    list.add(5);

    return list.shift() == 5;
}

bool Shift_OneNodeInList_ListIsEmpty(){
    LinkedList<int> list = LinkedList<int>();
    list.add(5);

    if(list.size() != 1){
        return false;
    }
    list.shift();
    return list.size() == 0;
}

bool Shift_ThreeNodeInList_ReturnsFirstData(){
    LinkedList<int> list = LinkedList<int>();
    list.add(0);
    list.add(1);
    list.add(2);

    return list.shift() == 0;
}

bool Shift_ThreeNodeInList_SizeIsSmaller(){
    LinkedList<int> list = LinkedList<int>();
    list.add(0);
    list.add(1);
    list.add(2);

    if(list.size() != 3){
        return false;
    }
    list.shift();
    return list.size() == 2;
}

bool Remove_ListEmpty_ThrowError(){
    LinkedList<int> list = LinkedList<int>();

    try{
        list.remove(0);
        return false;
    }catch (const std::out_of_range &e){
        return true;
    }
}

bool Remove_ThreeNodeInList_ReturnsFirstNode(){
    LinkedList<int> list = LinkedList<int>();
    list.add(0);
    list.add(1);
    list.add(2);

    return list.remove(0) == 0;
}

bool Remove_ThreeNodeInList_RemoveNode2_ReturnsLast(){
    LinkedList<int> list = LinkedList<int>();
    list.add(0);
    list.add(1);
    list.add(2);

    return list.remove(2) == 2;
}

bool Remove_ThreeNodeInList_SizeIsSmaller(){
    LinkedList<int> list = LinkedList<int>();
    list.add(0);
    list.add(1);
    list.add(2);

    if(list.size() != 3){
        return false;
    }
    list.remove(1);
    return list.size() == 2;
}

bool Get_ListEmpty_ThrowsError(){
    LinkedList<int> list = LinkedList<int>();
    try{
        list.get(0);
        return false;
    }catch (const std::out_of_range &e){
        return true;
    }
}

bool Get_ThreeNodesInList_ReturnsData(){
    LinkedList<int> list = LinkedList<int>();
    list.add(0);
    list.add(1);
    list.add(2);

    return list.get(1) == 1;
}

bool Clear_ListEmpty_SizeUnchanged(){
    LinkedList<int> list = LinkedList<int>();
    if(list.size() != 0){
        return false;
    }
    list.clear();
    return list.size() == 0;
}

bool Clear_ThreeNodeInList_ListIsEmpty(){
    LinkedList<int> list = LinkedList<int>();
    list.add(0);
    list.add(1);
    list.add(2);

    list.clear();

    return list.size() == 0;
}



int main(){
    bool state = true;
    int nb= 0;
    if(!Size_ListEmpty_Returns0()){
        std::cout << "Test failed for "<< "Size_ListEmpty_Returns0"<< std::endl;
        state= false;
        nb++;
    }

    if(!Size_ThreeNodeInList_Returns3()){
        std::cout << "Test failed for "<< "Size_ThreeNodeInList_Returns3"<< std::endl;
        state= false;
        nb++;
    }

    if(!Add_Place0_ListEmpty_ReturnsSize()){
        std::cout << "Test failed for "<< "Add_Place0_ListEmpty_ReturnsSize" << std::endl;
        state= false;
        nb++;
    }
    if(!Add_PlaceLargerThanSize_OneElementInList_AddNodeAtTheEnd()){
        std::cout << "Test failed for "<< "Add_PlaceLargerThanSize_OneElementInList_AddNodeAtTheEnd" << std::endl;
        state= false;
        nb++;
    }


    if(!Unshift_ListEmpty_ReturnSize1()){
        std::cout << "Test failed for "<< "Unshift_ListEmpty_ReturnSize1" << std::endl;
        state= false;
        nb++;
    }
    if(!Unshift_OneNodeInList_ReturnSize2()){
        std::cout << "Test failed for "<< "Unshift_OneNodeInList_ReturnSize2" << std::endl;
        state= false;
        nb++;
    }

    if(!Unshift_OneNodeInList_ExistingNodeShifted()){
        std::cout << "Test failed for "<< "Unshift_OneNodeInList_ExistingNodeShifted" << std::endl;
        state= false;
        nb++;
    }

    if(!Set_ListEmpty_ReturnsFalse()){
        std::cout << "Test failed for "<< "Set_ListEmpty_ReturnsFalse" << std::endl;
        state= false;
        nb++;
    }

    if(!Set_ThreeNodeInList_ModifyNode()){
        std::cout << "Test failed for "<< "Set_ThreeNodeInList_ModifyNode" << std::endl;
        state= false;
        nb++;
    }

    if(!Pop_ListEmpty_ReturnsNull()){
        std::cout << "Test failed for "<< "Pop_ListEmpty_ReturnsNull" << std::endl;
        state= false;
        nb++;
    }

    if(!Pop_TwoNodesInList_ReturnsLastNode()){
        std::cout << "Test failed for "<< "Pop_TwoNodesInList_ReturnsLastNode" << std::endl;
        state= false;
        nb++;
    }

    if(!Pop_TwoNodesInList_ListIsShorter()){
        std::cout << "Test failed for "<< "Pop_TwoNodesInList_ListIsShorter" << std::endl;
        state= false;
        nb++;
    }

    if(!Shift_OneNodeInList_ReturnsData()){
        std::cout << "Test failed for "<< "Shift_OneNodeInList_ReturnsData" << std::endl;
        state= false;
        nb++;
    }
    if(!Shift_OneNodeInList_ListIsEmpty()){
        std::cout << "Test failed for "<< "Shift_OneNodeInList_ListIsEmpty" << std::endl;
        state= false;
        nb++;
    }

    if(!Shift_ListEmpty_ReturnsNull()){
        std::cout << "Test failed for "<< "Shift_ListEmpty_ReturnsNull" << std::endl;
        state= false;
        nb++;
    }

    if(!Shift_ThreeNodeInList_ReturnsFirstData()){
        std::cout << "Test failed for "<< "Shift_ThreeNodeInList_ReturnsFirstData" << std::endl;
        state= false;
        nb++;
    }
    if(!Shift_ThreeNodeInList_SizeIsSmaller()){
        std::cout << "Test failed for "<< "Shift_ThreeNodeInList_SizeIsSmaller" << std::endl;
        state= false;
        nb++;
    }

    if(!Remove_ListEmpty_ThrowError()){
        std::cout << "Test failed for "<< "Remove_ListEmpty_ThrowError" << std::endl;
        state= false;
        nb++;
    }
    if(!Remove_ThreeNodeInList_ReturnsFirstNode()){
        std::cout << "Test failed for "<< "Remove_ThreeNodeInList_ReturnsFirstNode" << std::endl;
        state= false;
        nb++;
    }
    if(!Remove_ThreeNodeInList_RemoveNode2_ReturnsLast()){
        std::cout << "Test failed for "<< "Remove_ThreeNodeInList_RemoveNode2_ReturnsLast" << std::endl;
        state= false;
        nb++;
    }
    if(!Remove_ThreeNodeInList_SizeIsSmaller()){
        std::cout << "Test failed for "<< "Remove_ThreeNodeInList_SizeIsSmaller" << std::endl;
        state= false;
        nb++;
    }

    if(!Get_ListEmpty_ThrowsError()){
        std::cout << "Test failed for "<< "Get_ListEmpty_ThrowsError" << std::endl;
        state= false;
        nb++;
    }

    if(!Get_ThreeNodesInList_ReturnsData()){
        std::cout << "Test failed for "<< "Get_ThreeNodesInList_ReturnsData" << std::endl;
        state= false;
        nb++;
    }

    if(!Clear_ListEmpty_SizeUnchanged()){
        std::cout << "Test failed for "<< "Clear_ListEmpty_SizeUnchanged" << std::endl;
        state= false;
        nb++;
    }

    if(!Clear_ThreeNodeInList_ListIsEmpty()){
        std::cout << "Test failed for "<< "Clear_ThreeNodeInList_ListIsEmpty" << std::endl;
        state= false;
        nb++;
    }


    if(state){
        std::cout<< "All test have succeed";
    }else{
        std::cout << "Error " << nb << " test failed "<< std::endl;
    }
    return 0;
}
