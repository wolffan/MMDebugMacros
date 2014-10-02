//
//  Created by Michael May
//  Copyright (c) 2012-2014 Michael May.
//  MIT Licence. Use and enjoy.

// from http://iphoneincubator.com/blog/debugging/the-evolution-of-a-replacement-for-nslog
// DLog is almost a drop-in replacement for NSLog
// DLog();
// DLog(@"here");
// DLog(@"value: %d", x);
// Unfortunately this doesn't work DLog(aStringVariable); you have to do this instead DLog(@"%@", aStringVariable);

#ifndef _MMDebugMacros_h
#define _MMDebugMacros_h

#ifdef DEBUG

#define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#define DAssert(assertion,message) NSAssert(assertion,message)

#define DAssertClass(aClass,anObject) NSAssert([anObject isKindOfClass:[aClass class]], @"object is not of class expected")

NS_INLINE void DAssertNotNil(id object)
{
    NSCAssert(object != nil, @"Object was not and must not be");
}

NS_INLINE void DAssertPositiveNonZeroFloat(CGFloat value)
{
    NSCAssert(value > 0, @"");
}

#else

#define DLog(...)
#define DAssert(assertion,message)
#define DAssertClass(aClass,anObject)

NS_INLINE void DAssertNotNil(id object) {}

NS_INLINE void DAssertPositiveNonZeroFloat(CGFloat value) {}

#endif

// ALog always displays output regardless of the DEBUG setting

#define ALog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#endif