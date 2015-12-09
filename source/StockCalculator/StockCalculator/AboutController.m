//
//  AboutController.m
//  StockCalculator
//
//  Created by zuohaitao on 15/12/5.
//  Copyright © 2015年 zuohaitao. All rights reserved.
//

#import "AboutController.h"

@interface AboutController ()
-(void)openLocalURL;
@property NSURL* url;
@end

@implementation AboutController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.webView.delegate = self;
    [self openLocalURL];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)openLocalURL {
    self.webView.scalesPageToFit = NO;
    NSString* path = [[NSBundle mainBundle] pathForResource:@"about" ofType:@"html"];
    NSLog(@"%@", path);
    self.url = [NSURL fileURLWithPath:path];
    NSURLRequest* request = [NSURLRequest requestWithURL:self.url];
    [self.webView loadRequest:request];
    
}
#pragma - UIWebViewDelegate

- (void)webViewDidStartLoad:(UIWebView * _Nonnull)webView {
    self.indicator.hidden = NO;
}

- (void)webViewDidFinishLoad:(UIWebView * _Nonnull)webView {
    self.indicator.hidden = YES;
    if (self.url.fileURL) {
        self.webView.scalesPageToFit = YES;
    }
    
}

- (void)webView:(UIWebView * _Nonnull)webView
didFailLoadWithError:(NSError * _Nullable)error {
    return;
    //self.indicator.hidden = YES;
    //self.indicator.hidden = NO;
    //[self openLocalURL];
    
}

@end
