#include <gtest/gtest.h>
#include <libsbp/cpp/state.h>
#include <libsbp/cpp/message_traits.h>
#include <libsbp/cpp/message_handler.h>                                                     
class Test_auto_check_sbp_observation_490 : public ::testing::Test, public sbp::State, public sbp::IReader, public sbp::IWriter, sbp::MessageHandler<sbp_msg_ephemeris_gal_t>
{
public:
  Test_auto_check_sbp_observation_490() : ::testing::Test(), sbp::State(), sbp::IReader(), sbp::IWriter(), sbp::MessageHandler<sbp_msg_ephemeris_gal_t>(this), last_msg_(), last_sender_id_(), n_callbacks_logged_(), wr_(), rd_(), io_buf_()
  {
    set_reader(this);
    set_writer(this);
  }

  s32 read(uint8_t *buf, const uint32_t n) override {
    uint32_t real_n = n;
    memcpy(buf, io_buf_ + rd_, real_n);
    rd_ += real_n;
    return (s32)real_n;
  }

  s32 write(const uint8_t *buf, uint32_t n) override {
    uint32_t real_n = n;
    memcpy(io_buf_ + wr_, buf, real_n);
    wr_ += real_n;
    return (s32)real_n;
  }


protected:

  void handle_sbp_msg(uint16_t sender_id, const sbp_msg_ephemeris_gal_t &msg) override
  {
    last_msg_ = msg;
    last_sender_id_ = sender_id;
    n_callbacks_logged_++;
  }

  sbp_msg_ephemeris_gal_t last_msg_;
  uint16_t last_sender_id_;                                                   
  size_t n_callbacks_logged_;                                                 
  uint32_t wr_;
  uint32_t rd_;
  uint8_t io_buf_[1024];
};                                                                            
                                                                              
TEST_F(Test_auto_check_sbp_observation_490, Test)     
{

    uint8_t encoded_frame[] = {85,141,0,128,240,153,27,14,32,217,6,0,106,8,20,174,71,64,64,56,0,0,1,0,0,0,16,49,0,0,16,49,0,0,34,65,0,184,132,67,0,0,16,53,0,0,134,54,0,0,8,179,0,0,8,179,217,204,130,105,128,182,43,62,248,106,31,220,8,136,253,191,0,0,0,0,151,92,38,63,0,0,0,55,154,64,181,64,56,38,1,141,255,182,242,63,222,147,136,39,79,186,56,190,80,114,204,251,193,92,191,63,237,55,19,41,177,73,239,63,49,65,189,240,8,216,245,189,255,255,255,255,67,235,241,190,255,255,255,255,255,255,161,189,0,0,0,0,32,217,6,0,106,8,108,0,108,0,0,71,208, };

    sbp_msg_ephemeris_gal_t test_unpacked_msg{};
    test_unpacked_msg.af0 = -1.7088896129280325e-05;
    test_unpacked_msg.af1 = -8.185452315956353e-12;
    test_unpacked_msg.af2 = 0.0;
    test_unpacked_msg.bgd_e1e5a = 2.0954757928848267e-09;
    test_unpacked_msg.bgd_e1e5b = 2.0954757928848267e-09;
    test_unpacked_msg.c_ic = -3.166496753692627e-08;
    test_unpacked_msg.c_is = -3.166496753692627e-08;
    test_unpacked_msg.c_rc = 265.4375;
    test_unpacked_msg.c_rs = 10.125;
    test_unpacked_msg.c_uc = 5.364418029785156e-07;
    test_unpacked_msg.c_us = 3.993511199951172e-06;
    
    test_unpacked_msg.common.fit_interval = 14400;
    
    test_unpacked_msg.common.health_bits = 0;
    
    
    test_unpacked_msg.common.sid.code = 14;
    
    test_unpacked_msg.common.sid.sat = 27;
    
    
    test_unpacked_msg.common.toe.tow = 448800;
    
    test_unpacked_msg.common.toe.wn = 2154;
    
    test_unpacked_msg.common.ura = 3.119999885559082;
    
    test_unpacked_msg.common.valid = 1;
    test_unpacked_msg.dn = 3.2262058129932258e-09;
    test_unpacked_msg.ecc = 0.00017060607206076384;
    test_unpacked_msg.inc = 0.9777456094977858;
    test_unpacked_msg.inc_dot = -3.1787038343451465e-10;
    test_unpacked_msg.iodc = 108;
    test_unpacked_msg.iode = 108;
    test_unpacked_msg.m0 = -1.8457115744155868;
    test_unpacked_msg.omega0 = 1.16967730598334;
    test_unpacked_msg.omegadot = -5.757382675240872e-09;
    test_unpacked_msg.source = 0;
    test_unpacked_msg.sqrta = 5440.602401733398;
    
    test_unpacked_msg.toc.tow = 448800;
    
    test_unpacked_msg.toc.wn = 2154;
    test_unpacked_msg.w = 0.12250912091662625;
                                                                              
    EXPECT_EQ(send_message( 61568, test_unpacked_msg), SBP_OK);
                                                                              
    EXPECT_EQ(wr_, sizeof(encoded_frame));                               
    EXPECT_EQ(memcmp(io_buf_, encoded_frame, sizeof(encoded_frame)), 0);   
                                                                              
    while (rd_ < wr_) {                                             
      process();                                                              
    }

    EXPECT_EQ(n_callbacks_logged_, 1);
    EXPECT_EQ(last_sender_id_, 61568);
    EXPECT_EQ(test_unpacked_msg, last_msg_);
    EXPECT_LT((last_msg_.af0*100 - -1.70888961293e-05*100), 0.05);
    EXPECT_LT((last_msg_.af1*100 - -8.18545231596e-12*100), 0.05);
    EXPECT_LT((last_msg_.af2*100 - 0.0*100), 0.05);
    EXPECT_LT((last_msg_.bgd_e1e5a*100 - 2.09547579288e-09*100), 0.05);
    EXPECT_LT((last_msg_.bgd_e1e5b*100 - 2.09547579288e-09*100), 0.05);
    EXPECT_LT((last_msg_.c_ic*100 - -3.16649675369e-08*100), 0.05);
    EXPECT_LT((last_msg_.c_is*100 - -3.16649675369e-08*100), 0.05);
    EXPECT_LT((last_msg_.c_rc*100 - 265.4375*100), 0.05);
    EXPECT_LT((last_msg_.c_rs*100 - 10.125*100), 0.05);
    EXPECT_LT((last_msg_.c_uc*100 - 5.36441802979e-07*100), 0.05);
    EXPECT_LT((last_msg_.c_us*100 - 3.99351119995e-06*100), 0.05);
    
    EXPECT_EQ(last_msg_.common.fit_interval, 14400);
    
    EXPECT_EQ(last_msg_.common.health_bits, 0);
    
    
    EXPECT_EQ(last_msg_.common.sid.code, 14);
    
    EXPECT_EQ(last_msg_.common.sid.sat, 27);
    
    
    EXPECT_EQ(last_msg_.common.toe.tow, 448800);
    
    EXPECT_EQ(last_msg_.common.toe.wn, 2154);
    
    EXPECT_LT((last_msg_.common.ura*100 - 3.11999988556*100), 0.05);
    
    EXPECT_EQ(last_msg_.common.valid, 1);
    EXPECT_LT((last_msg_.dn*100 - 3.22620581299e-09*100), 0.05);
    EXPECT_LT((last_msg_.ecc*100 - 0.000170606072061*100), 0.05);
    EXPECT_LT((last_msg_.inc*100 - 0.977745609498*100), 0.05);
    EXPECT_LT((last_msg_.inc_dot*100 - -3.17870383435e-10*100), 0.05);
    EXPECT_EQ(last_msg_.iodc, 108);
    EXPECT_EQ(last_msg_.iode, 108);
    EXPECT_LT((last_msg_.m0*100 - -1.84571157442*100), 0.05);
    EXPECT_LT((last_msg_.omega0*100 - 1.16967730598*100), 0.05);
    EXPECT_LT((last_msg_.omegadot*100 - -5.75738267524e-09*100), 0.05);
    EXPECT_EQ(last_msg_.source, 0);
    EXPECT_LT((last_msg_.sqrta*100 - 5440.60240173*100), 0.05);
    
    EXPECT_EQ(last_msg_.toc.tow, 448800);
    
    EXPECT_EQ(last_msg_.toc.wn, 2154);
    EXPECT_LT((last_msg_.w*100 - 0.122509120917*100), 0.05);
}