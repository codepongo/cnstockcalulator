//
//  InputCell.m
//  cnstockcalculator
//
//  Created by zuohaitao on 15/10/14.
//  Copyright © 2015年 zuohaitao. All rights reserved.
//

#import "InputCellWithUnit.h"

@implementation InputCellWithUnit
- (IBAction)edit:(id)sender {
    //[UIKeyboard ]
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField{
    [textField resignFirstResponder];
    return YES;
}

@end
