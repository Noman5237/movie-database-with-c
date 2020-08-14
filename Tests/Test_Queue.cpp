/* Created By: Anonyman637
 * Created On: 8/14/2020; 8:41 PM
 */


#include <gtest/gtest.h>

#include "../lib/src/DataStruct/node.c"
#include "../lib/src/DataStruct/queue.c"
#include "../lib/src/exception.c"


class QueueTest : public ::testing::Test {

protected:
	void TearDown() override {
		destroy(queue);
	}
	
	void SetUp() override {
		queue = init();
		enqueue(queue, 5);
		enqueue(queue, 2);
		enqueue(queue, 3);
		enqueue(queue, 7);
		
		// We will check the return values and not fatal
		setDefaultExceptionHandlerFatality(VERBOSE);
	}
	
	Queue *queue;
};


TEST_F(QueueTest, Size) {
	// As far as we know the size should be 4
	EXPECT_EQ(size(queue), 4);
	
	// Lets pop some value and check the size again
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	
	// There should only one left to tell the tale
	EXPECT_EQ(size(queue), 1);
	
	traverse(queue);
	
}


TEST_F(QueueTest, Empty) {
	// The queue is not empty now
	EXPECT_FALSE(empty(queue));
	
	// Lets pop some data
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	
	// It should now be empty
	EXPECT_TRUE(empty(queue));
}


TEST_F(QueueTest, FrontNBack) {
	// Lets check the front and back
	EXPECT_EQ(front(queue), 5);
	EXPECT_EQ(back(queue), 7);

	// Lets dequeue some value
	dequeue(queue);
	dequeue(queue);

	// Lets check the front and back again
	EXPECT_EQ(front(queue), 3);
	EXPECT_EQ(back(queue), 7);

	// Emptying the queue
	dequeue(queue);
	dequeue(queue);

	// Enqueuing again
	enqueue(queue, 6);
	enqueue(queue, 3);
	enqueue(queue, 7);
	
	// Lets check the front and back one more time
	EXPECT_EQ(front(queue), 6);
	EXPECT_EQ(back(queue), 7);

	traverse(queue);
	
	// Lets hunt this queue
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	
	// There is no data in queue
	ASSERT_EQ(front(queue), INDEX_OUT_OF_BOUNDS);
	ASSERT_EQ(back(queue), INDEX_OUT_OF_BOUNDS);
	
	// And there is nothing more to be dequeued
	ASSERT_EQ(dequeue(queue), INDEX_OUT_OF_BOUNDS);
	
}

