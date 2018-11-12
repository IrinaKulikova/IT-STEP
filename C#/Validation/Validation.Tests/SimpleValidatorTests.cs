using static Xunit.Assert;
using Xunit;

namespace Validation.Tests
{
    public class SimpleValidatorTests
    {
        ISimpleValidator simpleValidator;

        public SimpleValidatorTests()
        {
            simpleValidator = new SimpleValidator();
        }

        [Fact]
        public void NotNull_Test_False()
        {
            False(simpleValidator.ContainsDigit(null));
            False(simpleValidator.ContainsSpecialCharacter(null));
            False(simpleValidator.IsOnlyDigit(null));
            False(simpleValidator.StartsFromDigit(null));
            False(simpleValidator.ContainsLowwerCharacter(null));
            False(simpleValidator.ContainsUpperCharacter(null));
            False(simpleValidator.IsLowerCase(null));
            False(simpleValidator.IsUpperCase(null));
            False(simpleValidator.MatchesRegExp(null, null));
            False(simpleValidator.MatchesRegExp(null, ""));
            False(simpleValidator.MatchesRegExp("", null));
            False(simpleValidator.LessThanMaxLength(null, uint.MaxValue));
            False(simpleValidator.MoreThanMinLength(null, uint.MaxValue));
            False(simpleValidator.LenBeetwen(null, uint.MaxValue, uint.MaxValue));
        }

        [Fact]
        public void NotEmpty_Test_False()
        {
            False(simpleValidator.ContainsDigit(""));
            False(simpleValidator.ContainsSpecialCharacter(""));
            False(simpleValidator.IsOnlyDigit(""));
            False(simpleValidator.StartsFromDigit(""));
            False(simpleValidator.ContainsLowwerCharacter(""));
            False(simpleValidator.ContainsUpperCharacter(""));
            False(simpleValidator.IsLowerCase(""));
            False(simpleValidator.IsUpperCase(""));
            False(simpleValidator.MatchesRegExp("", ""));
            False(simpleValidator.MatchesRegExp("", ""));
            False(simpleValidator.MatchesRegExp("", ""));
            False(simpleValidator.LessThanMaxLength("", uint.MaxValue));
            False(simpleValidator.MoreThanMinLength("", uint.MaxValue));
            False(simpleValidator.LenBeetwen("", uint.MaxValue, uint.MaxValue));
        }

        [Fact]
        public void ContainsDigit_Test_True()
        {
            True(simpleValidator.ContainsDigit("hello1word!"));
        }

        [Fact]
        public void ContainsDigit_Test_False()
        {
            False(simpleValidator.ContainsDigit("hello word!"));
        }

        [Fact]
        public void ContainsSpecialCharacter_Test_False()
        {
            False(simpleValidator.ContainsSpecialCharacter("hello word"));
        }

        [Fact]
        public void ContainsSpecialCharacter_Test_True()
        {
            string specials = @"!&*@%№|~$()?><}{-";
            for (int i = 0; i < specials.Length; i++)
            {
                True(simpleValidator.ContainsSpecialCharacter(specials[i] + "hello"));
            }
        }

        [Fact]
        public void IsOnlyDigit_Test_True()
        {
            True(simpleValidator.IsOnlyDigit("12398547"));
        }

        [Fact]
        public void IsOnlyDigit_Test_False()
        {
            False(simpleValidator.IsOnlyDigit("123456H"));
            False(simpleValidator.IsOnlyDigit("123456hhh"));
        }

        [Fact]
        public void StartsFromDigit_Test_True()
        {
            True(simpleValidator.StartsFromDigit("1abc"));
        }

        [Fact]
        public void StartsFromDigit_Test_False()
        {
            False(simpleValidator.StartsFromDigit(" abc"));
        }

        [Fact]
        public void ContainsUpperCharacter_Test_True()
        {
            True(simpleValidator.ContainsUpperCharacter("1Abc"));
        }

        [Fact]
        public void ContainsUpperCharacter_Test_False()
        {
            False(simpleValidator.ContainsUpperCharacter(" 1111 abc"));
        }

        [Fact]
        public void ContainsLowwerCharacter_Test_True()
        {
            True(simpleValidator.ContainsLowwerCharacter("1Abc"));
        }

        [Fact]
        public void ContainsLowwerCharacter_Test_False()
        {
           False(simpleValidator.ContainsLowwerCharacter(" 1111 AAA"));
        }

        [Fact]
        public void IsLowerCase_Test_True()
        {
           True(simpleValidator.IsLowerCase("bc"));
        }

        [Fact]
        public void IsLowerCase_Test_False()
        {
            False(simpleValidator.IsLowerCase(" 1111 AAA"));
            False(simpleValidator.IsLowerCase(" 1111"));
            False(simpleValidator.IsLowerCase(" AAA"));
        }

        [Fact]
        public void IsUpperCase_Test_True()
        {
            True(simpleValidator.IsUpperCase("JHGOIUJ"));
        }

        [Fact]
        public void IsUpperCase_Test_False()
        {
            False(simpleValidator.IsUpperCase(" 1111 AAA"));
            False(simpleValidator.IsUpperCase("1111"));
            False(simpleValidator.IsUpperCase("HHH AAA"));
        }

        [Fact]
        public void MatchesRegExp_Test_True()
        {
            True(simpleValidator.MatchesRegExp("JHGOIUJ", @"[A-Z]"));
            True(simpleValidator.MatchesRegExp("JHG1OIUJ", @"[A-Z1]"));
            True(simpleValidator.MatchesRegExp("JHGOIUJ", @"[\w]"));
            True(simpleValidator.MatchesRegExp("JHGOIUJ\t", @"\w+\s*"));
        }

        [Fact]
        public void MatchesRegExp_Test_False()
        {
            False(simpleValidator.MatchesRegExp("AAA", @"\d"));
            False(simpleValidator.MatchesRegExp("aaa", @"\d"));
            False(simpleValidator.MatchesRegExp("", @"\d"));
            False(simpleValidator.MatchesRegExp("hello", @"\s"));
        }

        [Fact]
        public void MoreThanMinLength_Test_True()
        {
            True(simpleValidator.MoreThanMinLength("JHGOIUJ", 4));
        }

        [Fact]
        public void MoreThanMinLength_Test_False()
        {
            False(simpleValidator.MoreThanMinLength("AAA", 5));
        }

        [Fact]
        public void LessThanMaxLength_Test_True()
        {
            True(simpleValidator.LessThanMaxLength("JHGOIUJ", 24));
        }

        [Fact]
        public void LessThanMaxLength_Test_False()
        {
            False(simpleValidator.LessThanMaxLength("AAA", 2));
        }

        [Fact]
        public void LenBeetwen_Test_True()
        {
            True(simpleValidator.LenBeetwen("JHGOIUJ", 3, 24));
            True(simpleValidator.LenBeetwen("J", 0, 2));
            True(simpleValidator.LenBeetwen("J", 1, 1));
        }

        [Fact]
        public void LenBeetwen_Test_False()
        {
            False(simpleValidator.LenBeetwen("JHGOIUJ", 12, 24));
            False(simpleValidator.LenBeetwen("JHGOIUJ", 22, 24));
        }
    }
}