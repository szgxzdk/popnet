#ifndef SIM_FLIT_H_
#define SIM_FLIT_H_

#include "index.h"
#include "SStd.h"
#include <vector>
#include <iostream>
#include <vector>

class flit_template {
	friend ostream& operator<<(ostream& os, const flit_template & ft);
	private:
		long flit_id_;
		int type_;
		add_type sor_addr_;
		add_type des_addr_;
		time_type start_time_;
		time_type finish_time_;
		Data_type data_;
		//added by Swain
		long packet_id_;
	public:
		long flit_id() {return flit_id_;}
		long flit_id() const {return flit_id_;}
		int type() {return type_;}
		int type() const {return type_;}
		add_type & sor_addr() {return sor_addr_;}
		const add_type & sor_addr() const {return sor_addr_;}
		add_type & des_addr() {return des_addr_;}
		const add_type & des_addr() const {return des_addr_;}

		time_type start_time() {return start_time_;}
		time_type start_time() const {return start_time_;}

		time_type finish_time() {return finish_time_;}
		time_type finish_time() const {return finish_time_;}

		//added by Swain
		long packet_id() {return packet_id_;}
		long packet_id() const {return packet_id_;}

		//added by Swain
		void set_type(int type) {type_ = type;}

		void set_start(time_type a) {start_time_ = a;}
		void set_finish(time_type a) {finish_time_ = a;}

		Data_type & data() {return data_;}
		const Data_type & data() const {return data_;}

		flit_template();
		flit_template(long a, int b, add_type & c, add_type & d,
					  time_type e, const Data_type & f, long packet_id);
		flit_template(const flit_template & a);
};
#endif
		

