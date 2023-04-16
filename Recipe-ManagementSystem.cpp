#include <iostream>
#include<fstream>
#include<string>
#include "Recipe.h"
#include "DataOfRecipe.h"

using namespace std;


int main()
{

    DataOfRecipe data;
    Recipe objectOfRecipe;
    string filePath = "RecipeDB.txt";
    data.loadRecipe(filePath);
    while (true) {
        cout << "-------Recipe Management System------\n"
            "1-ADD Recipe \n"
            "2-Edit Recipe Record \n"
            "3-Delete Recipe Record \n"
            "4-Search for Recipe Record By Name \n"
            "5-Display Recipe Information \n"
            "6-Sort Recipe By Name \n"
            "7-Exit \n"
            "====Enter your Choice==== : \n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Enter Recipe Details" << endl;
            string type;
            string nameOfRecipe;
            string ingredients;
            string preparationSteps;
            int cookingTime;
            cout << "Enter Type Of Recipe" << endl;
            cin >> type;
            cout << "Enter Name Of Recipe " << endl;
            cin >> nameOfRecipe;
            cout << "Enter Ingredients Of Recipe" << endl;
            cin >> ingredients;
            cout << "Enter PreparationSteps Of Recipe" << endl;
            cin >> preparationSteps;
            cout << "Enter CookingTime Of Recipe" << endl;
            cin >> cookingTime;
            Recipe recipe(type, nameOfRecipe, ingredients, preparationSteps, cookingTime);
            data.addRecipe(recipe);
            cout << "Recipe Record Added Successfully ! \n";
            break;
        }
        case 2:
        {
            string name;
            cout << "Enter Name Of Recipe" << endl;
            cin >> name;
            Recipe r = data.searchRecipeByName(name);
            cout << "Enter Recipe New Details" << endl;
            string type;
            string nameOfRecipe;
            string ingredients;
            string preparationSteps;
            int cookingTime;
            cout << "Enter Type Of Recipe" << endl;
            cin >> type;
            r.setType(type);
            cout << "Enter Name Of Recipe " << endl;
            cin >> nameOfRecipe;
            r.setNameOfRecipe(nameOfRecipe);
            cout << "Enter Ingredients Of Recipe" << endl;
            cin >> ingredients;
            r.setIngredients(ingredients);
            cout << "Enter PreparationSteps Of Recipe" << endl;
            cin >> preparationSteps;
            r.setPreparationSteps(preparationSteps);
            cout << "Enter CookingTime Of Recipe" << endl;
            cin >> cookingTime;
            r.setCookingTime(cookingTime);
            data.editRecipe(name, r);
            r.display();
            cout << "Recipe Edited" << endl;
            break;


        }
        case 3:
        {
            string Index;
            cout << "Enter Recipe Index : \n";
            cin >> Index;
            data.deleteRecipe(Index);
            data.saveRecipe(filePath);
            cout << "Recipe Record Deleted Successfully ! \n";
            break;
        }
        case 4:
        {
            string name;
            cout << "Enter Name :\n";
            cin >> name;
            Recipe r = data.searchRecipeByName(name);
            r.display();
            break;
        }
        case 5:
        {
            data.display();
            break;
        }
        case 6:
        {
            data.sortByName();
            data.saveRecipe(filePath);
            cout << "Record has been Sorted ! \n";
            break;
        }
        case 7:
            return 0;
        default:
            cout << "invalid info !\n";
            break;

        }
    }

    return 0;
}

