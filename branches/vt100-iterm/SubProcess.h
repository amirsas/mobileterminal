// SubProcess.h
#include <Foundation/Foundation.h>

@protocol InputDelegateProtocol
- (void)handleStreamOutput:(const char*)c length:(unsigned int)len;
@end

@interface SubProcess : NSObject
{
  int fd;
  id delegate;
}

// Delegate should support InputDelegateProtocol
- (id)initWithDelegate:(id)inputDelegate;
- (void)dealloc;
- (int)write:(const char*)c length:(unsigned int)len; 
- (void)startIOThread:(id)inputDelegate;
- (void)failure:(NSString*)message;

@end