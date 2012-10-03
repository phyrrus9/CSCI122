//
//  DetailViewController.h
//  ios6testmdetail
//
//  Created by Ethan Laur on 9/20/12.
//  Copyright (c) 2012 Ethan Laur. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface DetailViewController : UIViewController <UISplitViewControllerDelegate>

@property (strong, nonatomic) id detailItem;

@property (strong, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

@end
