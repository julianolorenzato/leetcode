# https://leetcode.com/problems/single-number

defmodule Solution do
  @spec single_number(nums :: [integer]) :: integer
  def single_number(nums) do
    Enum.reduce(nums, &Bitwise.bxor/2)
  end
end
