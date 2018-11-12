using Xunit;
using static Xunit.Assert;

namespace Validation.Tests
{
    public class ValitatorDateTests
    {
        readonly IValidatorData validatorData;
        readonly ISimpleValidator simpleValidator;

        public ValitatorDateTests()
        {
            simpleValidator = new SimpleValidator();
            validatorData = new ValidatorData(simpleValidator);
        }

        [Fact]
        public void NotNull_Test_False()
        {
            False(validatorData.ValidateAge(null));
            False(validatorData.ValidateMail(null));
            False(validatorData.ValidatePassword(null));
            False(validatorData.ValidatePostIndex(null));
            False(validatorData.ValidatePhone(null));
            False(validatorData.ValidateUrl(null));
            False(validatorData.ValidateUsername(null));
        }

        [Fact]
        public void NotEmpty_Test_False()
        {
            False(validatorData.ValidateAge(""));
            False(validatorData.ValidateMail(""));
            False(validatorData.ValidatePassword(""));
            False(validatorData.ValidatePostIndex(""));
            False(validatorData.ValidatePhone(""));
            False(validatorData.ValidateUrl(""));
            False(validatorData.ValidateUsername(""));
        }

        [Fact]
        public void ValidateAge_Test_True()
        {
            True(validatorData.ValidateAge("12"));
        }

        [Fact]
        public void ValidateAge_Test_False()
        {
            False(validatorData.ValidateAge("JHGOIUJ"));
            False(validatorData.ValidateAge(""));
            False(validatorData.ValidateAge("J12"));
        }

        [Fact]
        public void ValidatePassword_Test_True()
        {
            string specials = @"!&*@%№|~$()?><}{-";
            for (int i = 0; i < specials.Length; i++)
            {
                True(validatorData.ValidatePassword("jI1lk" + specials[i] + "oikk"));
            }
            True(validatorData.ValidatePassword("jI1lk$oi"));
            True(validatorData.ValidatePassword("1lk$oikY"));
        }

        [Fact]
        public void ValidatePassword_Test_False()
        {
            False(validatorData.ValidatePassword("1lk$oik"));
            False(validatorData.ValidatePassword("1lk$Y"));
            False(validatorData.ValidatePassword("Ylk$oik"));
            False(validatorData.ValidatePassword("1Y0oik"));
            False(validatorData.ValidatePassword("1l$oimnfjsj88HGHH%%%%k"));
        }


        [Fact]
        public void ValidateMail_Test_True()
        {
            True(validatorData.ValidateMail("inna@gmail.com"));
            True(validatorData.ValidateMail("i.j.ol@ma.ua"));
            True(validatorData.ValidateMail("4hg@gmail.pm"));
            True(validatorData.ValidateMail("44444@ma.ua"));

        }

        [Fact]
        public void ValidateMail_Test_False()
        {
            False(validatorData.ValidateMail("@mail.ru"));
            False(validatorData.ValidateMail("@ma.ua"));
            False(validatorData.ValidateMail("olma.ua"));
            False(validatorData.ValidateMail("i.j.ol@ma.u"));
            False(validatorData.ValidateMail("i.j.ol@ma.44"));
            False(validatorData.ValidateMail("44444@ma,ua"));
            False(validatorData.ValidateMail(@"44444@ma\sua"));
        }

        [Fact]
        public void ValidateUsername_Test_True()
        {
            True(validatorData.ValidateUsername("Vasyaa"));
            True(validatorData.ValidateUsername("m1"));
            True(validatorData.ValidateUsername("m"));
        }

        [Fact]
        public void ValidateUsername_Test_False()
        {
            False(validatorData.ValidateUsername("1m"));
            False(validatorData.ValidateUsername("1"));
        }

        [Fact]
        public void ValidatePhone_Test_True()
        {
            True(validatorData.ValidatePhone("38(063)072-93-13"));
            True(validatorData.ValidatePhone("+38(063)072-93-13"));
            True(validatorData.ValidatePhone("38063072-93-13"));
            True(validatorData.ValidatePhone("38(063)0729313"));
            True(validatorData.ValidatePhone("380630729313"));
            True(validatorData.ValidatePhone("38(063)072 93 13"));
        }

        [Fact]
        public void ValidatePhone_Test_False()
        {
            False(validatorData.ValidatePhone("38-063-072-93-13"));
            False(validatorData.ValidatePhone("8(063)072-93-13"));
            False(validatorData.ValidatePhone("063-072-93-13"));
            False(validatorData.ValidatePhone("+aa(aaa)aa-aa-aa"));
        }

        [Fact]
        public void ValidatePostIndex_Test_True()
        {
            True(validatorData.ValidatePostIndex("11111"));
        }

        [Fact]
        public void ValidatePostIndex_Test_False()
        {
            False(validatorData.ValidatePostIndex("1111"));
            False(validatorData.ValidatePostIndex("111111"));
            False(validatorData.ValidatePostIndex("aaaaa"));
            False(validatorData.ValidatePostIndex("     "));
        }

        [Fact]
        public void ValidateUrl_Test_True()
        {
            True(validatorData.ValidateUrl("http://i.ua"));
            True(validatorData.ValidateUrl("https://44i.ua"));

        }

        [Fact]
        public void ValidateUrl_Test_False()
        {
            False(validatorData.ValidateUrl("htts:/i.ua"));
            False(validatorData.ValidateUrl("htts:/i.ua"));
            False(validatorData.ValidateUrl("https://ua"));
        }
    }
}
