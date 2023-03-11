<?php
// Queue interface
interface Queue
{
    public function enqueue($item);
    public function dequeue();
    public function front();
    public function isEmpty();
}

// Queue implementation
class MyQueue implements Queue
{
    private $data = [];

    public function enqueue($item)
    {
        array_push($this->data, $item);
    }

    public function dequeue()
    {
        if ($this->isEmpty()) {
            throw new Exception("Queue is empty.");
        }
        return array_shift($this->data);
    }

    public function front()
    {
        if ($this->isEmpty()) {
            throw new Exception("Queue is empty.");
        }
        return $this->data[0];
    }

    public function isEmpty()
    {
        return empty($this->data);
    }
}

// Usage
$queue = new MyQueue();
$queue->enqueue(10);
$queue->enqueue(20);
$queue->enqueue(30);
echo $queue->dequeue() . "\n"; // 10
echo $queue->front() . "\n"; // 20
echo $queue->dequeue() . "\n"; // 20
echo $queue->isEmpty() . "\n"; // false
?>