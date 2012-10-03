//
//  MasterViewController.h
//  ios6testmdetail
//
//  Created by Ethan Laur on 9/20/12.
//  Copyright (c) 2012 Ethan Laur. All rights reserved.
//

#import <UIKit/UIKit.h>

@class DetailViewController;

@interface MasterViewController : UITableViewController

@property (strong, nonatomic) DetailViewController *detailViewController;

@end
