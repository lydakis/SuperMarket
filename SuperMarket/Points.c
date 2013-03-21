//
//  Points.c
//  SuperMarket
//
//  Created by George Lydakis on 3/16/13.
//  Copyright (c) 2013 Brainstorm. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Points.h"
#include "FileOperations.h"

int calcPrice(char productName[], int day, int quantity, PriceData data)
{
    int i = 0;
    int check;
    int pr_temp = 0, i_max = -1;
    int price = 0;
    
    switch (day) {
        case 1: {
            do {
                check = strcmp(productName, data.Monday[i++].productName);
                
                if (check == 0) {
                    if (data.Monday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (strchr(data.Monday[i].productName, (int)'P') != NULL);
            
            if (i_max != -1 && data.Monday[i_max].price != 0) {
                price = quantity * data.Monday[i_max].price;
            }
            else {
                price = 10 * quantity;
            }
            
        }
            break;
        case 2: {
            do {
                check = strcmp(productName, data.Tuesday[i++].productName);
                
                if (check == 0) {
                    if (data.Tuesday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (strchr(data.Monday[i].productName, (int)'P') != NULL);
            
            if (i_max != -1 && data.Tuesday[i_max].price != 0) {
                price = quantity * data.Tuesday[i_max].price;
            }
            else {
                price = 10 * quantity;
            }
            
        }
            break;
        case 3: {
            do {
                check = strcmp(productName, data.Wednesday[i++].productName);
                
                if (check == 0) {
                    if (data.Wednesday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (strchr(data.Wednesday[i].productName, (int)'P') != NULL);
            
            if (i_max != -1 && data.Wednesday[i_max].price != 0) {
                price = quantity * data.Wednesday[i_max].price;
            }
            else {
                price = 10 * quantity;
            }
            
        }
            break;
        case 4: {
            do {
                check = strcmp(productName, data.Thursday[i++].productName);
                
                if (check == 0) {
                    if (data.Thursday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (strchr(data.Thursday[i].productName, (int)'P') != NULL);
            
            if (i_max != -1 && data.Thursday[i_max].price != 0) {
                price = quantity * data.Thursday[i_max].price;
            }
            else {
                price = 10 * quantity;
            }
            
        }
            break;
        case 5: {
            do {
                check = strcmp(productName, data.Friday[i++].productName);
                
                if (check == 0) {
                    if (data.Friday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (strchr(data.Friday[i].productName, (int)'P') != NULL);
            
            if (i_max != -1 && data.Friday[i_max].price != 0) {
                price = quantity * data.Friday[i_max].price;
            }
            else {
                price = 10 * quantity;
            }
            
        }
            break;
        case 6: {
            do {
                check = strcmp(productName, data.Saturday[i++].productName);
                
                if (check == 0) {
                    if (data.Saturday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (strchr(data.Saturday[i].productName, (int)'P') != NULL);
            
            if (i_max != -1 && data.Saturday[i_max].price != 0) {
                price = quantity * data.Saturday[i_max].price;
            }
            else {
                price = 10 * quantity;
            }
            
        }
            break;
        case 7: {
            do {
                check = strcmp(productName, data.Sunday[i++].productName);
                
                if (check == 0) {
                    if (data.Sunday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (strchr(data.Sunday[i].productName, (int)'P') != NULL);
            
            if (i_max != -1 && data.Sunday[i_max].price != 0) {
                price = quantity * data.Sunday[i_max].price;
            }
            else {
                price = 10 * quantity;
            }
            
        }
            break;
        default:
            price = 10 * quantity;
            break;
    }
    
    return price;
}

double findMultiplier(char productName[], MultiplierData data[])
{
    double multiplier = 0.5;
    int i = 0;
    
    for (i = 0; strchr(data[i].product, (int)'P') != NULL; i++) {
        if (strcmp(productName, data[i].product) == 0) {
            multiplier = data[i].multiplier;
            break;
        }
    }
    
    return multiplier;
}

double calcPoints(char productName[], int day, int quantity, PriceData pr_data, MultiplierData mult_data[])
{
    double multiplier = 0.5;
    int i = 0;
    int check;
    int pr_temp = 0, i_max = -1;
    int price = 0;
    
    for (i = 0; mult_data[i].multiplier != 0; i++) {
        if (strcmp(productName, mult_data[i].product) == 0) {
            multiplier = mult_data[i].multiplier;
            break;
        }
    }
    
    i = 0;

    
    switch (day) {
        case 1: {
            do {
                check = strcmp(productName, pr_data.Monday[i++].productName);
                
                if (check == 0) {
                    if (pr_data.Monday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (pr_data.Monday[i].price != 0);
            
            if (i_max != -1 && pr_data.Monday[i_max].price != 0) {
                price = quantity * pr_data.Monday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 2: {
            do {
                check = strcmp(productName, pr_data.Tuesday[i++].productName);
                
                if (check == 0) {
                    if (pr_data.Tuesday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (pr_data.Tuesday[i].price != 0);
            
            if (i_max != -1 && pr_data.Tuesday[i_max].price != 0) {
                price = quantity * pr_data.Tuesday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 3: {
            do {
                check = strcmp(productName, pr_data.Wednesday[i++].productName);
                
                if (check == 0) {
                    if (pr_data.Wednesday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (pr_data.Wednesday[i].price != 0);
            
            if (i_max != -1 && pr_data.Wednesday[i_max].price != 0) {
                price = quantity * pr_data.Wednesday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 4: {
            do {
                check = strcmp(productName, pr_data.Thursday[i++].productName);
                
                if (check == 0) {
                    if (pr_data.Thursday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (pr_data.Thursday[i].price != 0);
            
            if (i_max != -1 && pr_data.Thursday[i_max].price != 0) {
                price = quantity * pr_data.Thursday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 5: {
            do {
                check = strcmp(productName, pr_data.Friday[i++].productName);
                
                if (check == 0) {
                    if (pr_data.Friday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (pr_data.Friday[i].price != 0);
            
            if (i_max != -1 && pr_data.Friday[i_max].price != 0) {
                price = quantity * pr_data.Friday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 6: {
            do {
                check = strcmp(productName, pr_data.Saturday[i++].productName);
                
                if (check == 0) {
                    if (pr_data.Saturday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (pr_data.Saturday[i].price != 0);
            
            if (i_max != -1 && pr_data.Saturday[i_max].price != 0) {
                price = quantity * pr_data.Saturday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        case 7: {
            do {
                check = strcmp(productName, pr_data.Sunday[i++].productName);
                
                if (check == 0) {
                    if (pr_data.Sunday[i-1].price > pr_temp) {
                        i_max = i - 1;
                    }
                }
                
            } while (pr_data.Sunday[i].price != 0);
            
            if (i_max != -1 && pr_data.Sunday[i_max].price != 0) {
                price = quantity * pr_data.Sunday[i_max].price;
            }
            else {
                for (i = 0; pr_data.maxPrices[i].price != 0; i++) {
                    if (strcmp(productName, pr_data.maxPrices[i].productName) == 0) {
                        price = pr_data.maxPrices[i].price * quantity;
                        break;
                    }
                }
            }
            
        }
            break;
        default:
            price = 10 * quantity;
            break;
    }
    
    
    return price * multiplier;
}

